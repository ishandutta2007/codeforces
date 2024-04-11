#include <iostream>
using namespace std;

int N, K;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> K;

    for(int i=0; i<N-K; i++)
        cout << i+1 << " ";

    bool w = true;
    int lo = N-K+1, hi = N;
    for(int i=N-K; i<N; i++){
        if(w) cout << hi-- << " ";
        else cout << lo++ << " ";
        w = !w;
    }

    cout<<endl;
    return 0;
}