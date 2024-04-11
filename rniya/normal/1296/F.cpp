#include <bits/stdc++.h>
using namespace std;
const int MAX=5010;

int n,m,u,v,ok;
vector<pair<int,int>> G[MAX];
int ans[MAX],a[MAX],b[MAX],g[MAX],check[MAX];

void dfs1(int v,int p,int id){
    for (auto e:G[v]){
        int u=e.first;
        if (u==p) continue;
        dfs1(u,v,id);
        if (check[u]){
            ans[e.second]=max(ans[e.second],g[id]);
            check[v]=1;
        }
    }
}

void dfs2(int v,int p,int id){
    for (auto e:G[v]){
        int u=e.first;
        if (u==p) continue;
        dfs2(u,v,id);
        if (check[u]){
            if (ans[e.second]==g[id]) ok=1;
            check[v]=1;
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<n-1;++i){
        cin >> u >> v; --u,--v;
        G[u].emplace_back(v,i);
        G[v].emplace_back(u,i);
        ans[i]=1;
    }
    cin >> m;
    for (int i=0;i<m;++i){
        cin >> a[i] >> b[i] >> g[i]; --a[i],--b[i];
        for (int j=0;j<n;++j) check[j]=0;
        check[b[i]]=1;
        dfs1(a[i],-1,i);
    }
    for (int i=0;i<m;++i){
        for (int j=0;j<n;++j) check[j]=0;
        check[b[i]]=1; ok=0;
        dfs2(a[i],-1,i);
        if (!ok){cout << -1 << '\n'; return 0;}
    }
    for (int i=0;i<n-1;++i) cout << ans[i] << (i!=n-2?' ':'\n');
}