#include <iostream>
using namespace std;

int N, K, T;

int main(){
    cin >> N >> K;
    for(int i=0; i<N; i++){
        int v; cin >> v;
        if(v+K > 5) continue;
        T++;
    }

    cout << T/3 << endl;
    return 0;
}