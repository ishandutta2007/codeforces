#include <iostream>
using namespace std;

string s;
int N, M, K, r[222222];

int main(){
    ios_base::sync_with_stdio(false);
    
    cin >> s >> M;
    N = s.length();

    for(int i=0; i<M; i++){
        cin >> K;
        r[K-1]++;
        r[N+1-K]--;
    }

    int rev = 0;
    for(int i=0; i<N; i++){
        rev += r[i];
        if(rev%2 == 0) cout << s[i];
        else cout << s[N-1-i];
    }

    cout << endl;
}