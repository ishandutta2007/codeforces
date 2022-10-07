#include<bits/stdc++.h>
using namespace std;
vector<int> v[200009];
vector<int> W[200009];
int f[200009],g[200009],h[200009],cc[200009],w[200009],c,n,m;
long long su[200009];
void dfs(int x){
    g[x] =1;
    su[c]+=w[x];
    cc[x] = c;
    for(int y : v[x])
        if(!g[y]) dfs(y);
}
long long ans  =0 ;
void bfs(int x, long long S){
    S += su[x];
    h[x] = 1;
    ans = max(ans, S);
    for(int y : W[x])
        if(!h[y]) bfs(y, S);

}
main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> w[i];
    }
    for(int i = 1; i <=m; i++){
        int u,a;
        cin>>u>>a;
        v[a].push_back(u);
        v[u].push_back(a);
        f[a]++;
        f[u]++;
    }
    queue<int> q;
    for(int i =1 ; i <= n; i++){
        if(f[i] == 1) q.push(i), g[i] = 1,cc[i] = ++c, su[c] = w[i];
    }
    while(q.size()){

        int x = q.front();
        q.pop();
        for(int y : v[x])
            if(!g[y]) {f[y] --; if(f[y] == 1) {q.push(y); g[y] = 1; cc[y] = ++c; su[c] = w[y];}}
    }
    int k = 0;
    for(int i = 1; i <= n; i++)
        if(g[i] == 0) {++c,dfs(i); k = i;}
    for(int i = 1; i <= n; i++)
        for(int j : v[i])
            if(cc[i] != cc[j]) W[cc[i]].push_back(cc[j]);
     int s;
     cin>>s;
     bfs(cc[s],0);
     for(int i =1; i <= n; i++) h[i] = 0;

    if(k)  bfs(cc[k],0);
     cout<<ans<<endl;
}