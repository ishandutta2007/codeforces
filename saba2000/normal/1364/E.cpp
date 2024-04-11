#include<bits/stdc++.h>
using namespace std;
int ans[10009];
int f[10009];
int V[10009];
int ask(int i, int j){
    cout <<"? "<<i<<" "<<j<<endl;
    int x;
    cin >> x;
    return x;
}
int g[100][100];
main(){
    srand(time(0));
    int n;
    cin >> n;
    vector<int> v;
    while(1){
        int i = rand() % n + 1;
        if(f[i] == 0) v.push_back(i);
        f[i] = 1;
        if(v.size() == 15 || v.size() == n) break;
    }
    for(int i = 0; i < v.size(); i++){
        for(int j = i+1; j < v.size(); j++){
            g[i][j] = g[j][i] = ask(v[i], v[j]);
        }

    }
    int A = 1, z = 10;
    for(int i = 0; i < v.size(); i++){
        int x = 2047;
        for(int j = 0; j < v.size(); j++){
            if(i != j) x = (x & g[i][j]);
        }
        if(__builtin_popcount(x) <= z) A = v[i], z = __builtin_popcount(x);
    }
    vector<int> S;
    S.push_back(A);
    for(int i = 1; i <= n; i++)
        if(i != A) S.push_back(i);
    while(S.size() > 1){
        if(S.size() != n) swap(S[0], S[1]);
        int x = 2048, y = 2047;
        for(int i = 1; i < S.size(); i++){
            V[i] = ask(S[0], S[i]);
            x = min(x, V[i]);
            y = (y & V[i]);
        }
        if(y == 0) {S = {S[0]}; break;}
        vector<int> W = {S[0]};
        if(S.size() == 2) break;
        for(int i = 1; i < S.size(); i++){
            if(V[i] == x) W.push_back(S[i]);
        }
        S = W;
    }
    int u = S[0];
    for(int i = 1; i <= n; i++){
        if(i != u) ans[i] = ask(i, u);
    }
    cout<<"! ";
    for(int i = 1; i <= n ;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}
/*


*/