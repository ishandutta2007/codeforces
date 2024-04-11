#include<bits/stdc++.h>
using namespace std;
int ok = 1;
int f[200009];
vector<int> v[200009],w[200009];
void dfs(int x){
    f[x] = 1;
    for(int  y : v[x]){
        if(f[y] == 1) ok = 0;
        if(!f[y]) dfs(y);
    }
    f[x] = 2;
}
int g[200009],l[200009];
void dfs1(int x){
    g[x] = 1;
    for(int y : v[x]){
        if(g[y]) continue;
        dfs1(y);
    }
}
void dfs2(int x){
    l[x] =1;
    for(int y : w[x]){
        if(l[y]) continue;
        dfs2(y);
    }
}
main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        w[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(!f[i]) dfs(i);
    }
    if(!ok){
        cout << -1 << endl;
        return 0;
    }
    int ans= 0;
    string S = "";
    for(int i = 1; i <= n; i++){
        if(!g[i] && !l[i]){
            ans++;
            S += 'A';
        }
        else{
            S += 'E';
        }
        dfs1(i);
        dfs2(i);

    }
    cout<<ans<<endl<<S<<endl;
}