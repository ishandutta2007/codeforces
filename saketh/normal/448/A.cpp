#include <iostream>
using namespace std;

int A, AI, B, BI, N;

int main(){
    for(int i=0; i<3; i++){
        cin >> AI;
        A += AI;
    }

    for(int i=0; i<3; i++){
        cin >> BI;
        B += BI;
    }

    cin >> N;
    int need = (A+4)/5 + (B+9)/10;
    cout << ((need <= N)?"YES":"NO") << endl;
    return 0;
}