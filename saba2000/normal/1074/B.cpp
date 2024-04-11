#include<bits/stdc++.h>
using namespace std;
int x[1009], y[1009];
vector<int> v[1009];
int X[1009], Y[1009];
int f[1009];
char A = 'A', B = 'B', C = 'C';
int ask(char a, int b){
    cout << a << " "<<b<<endl;
    if(a == C) return -1;
    int ans;
    scanf("%d", &ans);
    return ans;
}
int ans = -1;
void dfs(int a){
    f[a] = 1;
    if(X[a]) {
        ans = a;
        return;
    }
    for(int b : v[a])
        if(!f[b]) dfs(b);
}
void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int k1; cin >> k1;
    for(int i = 1; i <= k1; i++){
        scanf("%d", &x[i]);
        X[x[i]] = 1;
    }
    int k2; cin >> k2;
    for(int i = 1; i <= k2; i++){
        scanf("%d", &y[i]);
        Y[y[i]] = 1;
    }
    int ha = ask(B, y[1]);
    if(X[ha]){
        ask(C, ha);
    } else{
        dfs(ha);
        int hu = ask(A, ans);
        if(Y[hu]){
            ask(C, ans);
        }
        else{
            ask(C, -1);
        }
    }
    for(int i = 0; i <= n; i++)
        v[i].clear(), X[i] = 0, Y[i] = 0, f[i] = 0;
    ans = -1;
}
main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}