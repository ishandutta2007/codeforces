#include<bits/stdc++.h>
#define ll long long
using namespace std;
int f[100009];
int ind[5009][5009];
int b[5009];
int u[5009],V[5009],g[5009];
vector<int> v[5009];
bool dfs(int x, int y, int p, int G){
    if(x== y) return 1;
    for(int z : v[x]){
        if(z == p) continue;
        if(dfs(z,y,x,G)) {
            b[ind[x][z]] = max(b[ind[x][z]], G);
            return 1;
        }
    }
    return 0;
}
int dfs1(int x, int y, int p){
    if(x== y) return 1e9;
    for(int z : v[x]){
        if(z == p) continue;
        int u = (dfs1(z,y,x));
        if(u) return min(b[ind[x][z]], u);
    }
    return 0;
}
main(){
    int n, m;
    cin >> n;
    for(int i = 1; i <= n- 1; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        ind[a][b] = i;
        ind[b][a] = i;
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> u[i] >> V[i] >> g[i];
        dfs(u[i], V[i], -1,g[i]);
    }
    for(int i = 1; i <= m; i++){
        if(dfs1(u[i],V[i],-1) != g[i]){
            cout<<-1<<endl;
            return 0;
        }
    }
    for(int i = 1; i <=n-1; i++)
        cout<<max(1,b[i])<<" ";
}