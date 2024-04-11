#include <iostream>
using namespace std;

int N, K;

int main(){
    cin >> N >> K;
    
    int M = (N * N + 1) / 2;
    if(K>M){ cout << "NO" << endl; return 0; }

    cout << "YES" << endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if((i+j)%2==0 && K>0){
                cout << "L";
                K--;
            }
            else cout << "S";
        }
        cout << endl;
    }
}