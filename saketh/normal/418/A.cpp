#include<iostream>
using namespace std;

int N, K;

int main(){
    cin >> N >> K;
    
    if(K+K > N-1){
        cout << "-1" << endl;
        return 0;
    }
    
    cout << N * K << endl;
    for(int i=0; i<N; i++){
        for(int j=1; j<=K; j++){
            int b = (i+j) % N;
            cout << i+1 << " " << (b%N)+1 << endl;
        }
    }
    
    return 0;
}