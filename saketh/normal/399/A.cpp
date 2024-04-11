#include <iostream>
using namespace std;

int N, P, K;

int main(){
    cin >> N >> P >> K;
    
    if(P-K > 1) cout << "<< ";
    for(int p=P-K; p<=P+K; p++){
        if(p<1 || p>N) continue;
        if(p==P) cout << "(" << p << ") ";
        else cout << p << " ";
    }
    if(P+K < N) cout << ">>";
    cout << endl;
    return 0;
}