#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


struct Paciente {
    int numeroCaracteristico;
    string nome;
    string dataNascimento;
    string comorbidade;
};


void cadastrarPaciente(vector<Paciente>& pacientes, int& numeroCaracteristico) {
    char confirmacao;

    do {
        Paciente novoPaciente;
        novoPaciente.numeroCaracteristico = numeroCaracteristico++;

        cout << "Digite o nome do paciente: ";
        cin.ignore(); 
        getline(cin, novoPaciente.nome);
        cout << "Digite a data de nascimento do paciente: ";
        getline(cin, novoPaciente.dataNascimento);
        cout << "Digite a comorbidade do paciente: ";
        getline(cin, novoPaciente.comorbidade);

        
        pacientes.push_back(novoPaciente);

        cout << "Paciente cadastrado com sucesso. Número Característico: " << novoPaciente.numeroCaracteristico << "\n";

        cout << "Deseja cadastrar outro paciente? (s/n): ";
        cin >> confirmacao;

    } while (confirmacao == 's' || confirmacao == 'S');
}


void consultarPacientePorNumero(const vector<Paciente>& pacientes) {
    int numeroConsulta;
    cout << "Digite o número característico do paciente que deseja consultar: ";
    cin >> numeroConsulta;

    
    for (const auto& paciente : pacientes) {
        if (paciente.numeroCaracteristico == numeroConsulta) {
            cout << "Número Característico: " << paciente.numeroCaracteristico << "\n";
            cout << "Nome: " << paciente.nome << "\n";
            cout << "Data de Nascimento: " << paciente.dataNascimento << "\n";
            cout << "Comorbidade: " << paciente.comorbidade << "\n\n";
            return; 
        }
    }

    cout << "Paciente não encontrado.\n";
}


void gerarArquivo(const vector<Paciente>& pacientes) {
    ofstream arquivo("pacientes.txt");
    if (arquivo.is_open()) {
        for (const auto& paciente : pacientes) {
            arquivo << "Número Característico: " << paciente.numeroCaracteristico << "\n";
            arquivo << "Nome: " << paciente.nome << "\n";
            arquivo << "Data de Nascimento: " << paciente.dataNascimento << "\n";
            arquivo << "Comorbidade: " << paciente.comorbidade << "\n\n";
        }
        arquivo.close();
        cout << "Arquivo gerado com sucesso.\n";
    } else {
        cout << "Erro ao abrir o arquivo.\n";
    }
}

int main() {
    vector<Paciente> pacientes; 
    int numeroCaracteristico = 1; 
    int escolha;

    do {
        
        cout << "\nMenu:\n";
        cout << "1. Cadastrar\n";
        cout << "2. Consultar paciente\n";
        cout << "3. Gerar Arquivo\n";
        cout << "4. Sair\n";
        cout << "Escolha uma opção (1-4): ";

        
        cin >> escolha;

        
        switch (escolha) {
            case 1:
                cadastrarPaciente(pacientes, numeroCaracteristico);
                break;
            case 2:
                consultarPacientePorNumero(pacientes);
                break;
            case 3:
                gerarArquivo(pacientes);
                break;
            case 4:
                cout << "Saindo do programa.\n";
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }

    } while (escolha != 4);

    return 0;
}
