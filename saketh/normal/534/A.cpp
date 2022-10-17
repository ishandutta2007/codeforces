#include <iostream>
using namespace std;

int N;

int main(){
    cin >> N;

    if(N <= 2){
        cout << "1\n1\n";
    }
    else if(N == 3){
        cout << "2\n1 3\n";
    }
    else if(N == 4){
        cout << "4\n3 1 4 2\n";
    }
    else if(N%2){
        cout << N << "\n";
        cout << N/2+1 << " ";
        for(int i=0; i<N/2; i++)
            cout << i+1 << " " << N/2+2+i << " ";
        cout << "\n";
    }
    else{
        cout << N << "\n";
        for(int i=0; i<N/2; i++)
            cout << i+1 << " " << N/2+i+1 << " ";
        cout << "\n";
    }
}