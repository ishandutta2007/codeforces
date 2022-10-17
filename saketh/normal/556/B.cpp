#include <iostream>
using namespace std;

int N;
int g[1028];

bool eq(int i, int j){
    return i % N == j % N;
}

int main(){
    cin >> N;
    
    bool good = true;
    for(int i=0; i<N; i++){
        cin >> g[i];
        for(int j=0; j<i; j++){
            if((i^j)&1) good &= eq(i+j, g[i]+g[j]);
            else good &= eq(i-j+N, g[i]-g[j]+N);
        }
    }
        
    cout << (good ? "Yes" : "No") << "\n";
}