#include <iostream>
using namespace std;

int N, M, A, C, G;

int main(){
    cin >> N >> M;

    for(int i=0; i<N; i++){
        cin >> G;
        if((C+G) <= M)
            C += G;
        else{
            A++;
            C = G;
        }
    }

    cout << A + (C>0) << endl;
    return 0;
}