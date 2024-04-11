#include <bits/stdc++.h>
using namespace std;

string S[9];

void solve(){
    for (int i=0;i<3;++i){
        vector<int> perm(3);
        iota(perm.begin(),perm.end(),0);
        do {
            int ok=0;
            for (int j=0;j<3;++j){
                if (S[3*i+perm[j]][3*j+i]==S[3*i+perm[(j+1)%3]][3*((j+1)%3)+i]) break;
                if (j==2){
                    char c=S[3*i+perm[0]][i];
                    S[3*i+perm[0]][i]=S[3*i+perm[1]][3+i];
                    S[3*i+perm[1]][3+i]=S[3*i+perm[2]][6+i];
                    S[3*i+perm[2]][6+i]=c;
                    ok=1;
                }
            }
            if (ok) break;
        } while(next_permutation(perm.begin(),perm.end()));
    }
    for (int i=0;i<9;++i) cout << S[i] << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        for (int i=0;i<9;++i) cin >> S[i];
        solve();
    }
}