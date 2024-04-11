#include <iostream>
using namespace std;

int N, M, S, B;

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        int v; cin >> v;
        S += v;
        B = max(B, v);
    }

    cout << (S-B<=M?"YES":"NO") << endl;
    return 0;
}