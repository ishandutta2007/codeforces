#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N = 300000+10;
typedef long long LL;
int n,m;vector<int> g[N];
vector< pair<int,int> > vec[N]; 
LL bit[N];
void add(int pos,int x){
    while(pos<N) {
        bit[pos]+=x; pos+=pos&-pos;
    }
}
LL sum(int pos){
    LL ans=0;
    while(pos>0){
        ans+=bit[pos]; pos-=pos&-pos;
    } return ans;
}
int dep[N]; LL ans[N];
void dfs(int u,int p){
    //printf("u=%d,p=%d\n", u,p);
    dep[u]=dep[p]+1;
    for(auto p: vec[u]) {
        int r = min(n+1,dep[u]+p.first+1);
        add(dep[u], p.second);
        add(r, -p.second);
    }
    ans[u]=sum(dep[u]);
    for(int i=0;i<g[u].size();i++) {
        int v=g[u][i]; if(v==p)continue;
        dfs(v,u);
    }
    for(auto p: vec[u]) {
        int r = min(n+1,dep[u]+p.first+1);
        add(dep[u], -p.second);
        add(r, +p.second);
    }
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v); g[v].push_back(u);
    }
    scanf("%d",&m);
    while(m--) {
        int v,d,x; scanf("%d%d%d",&v,&d,&x);
        vec[v].push_back(make_pair(d,x));
    }
    dfs(1,1);
    for(int i=1;i<=n;i++)printf("%lld ", ans[i]);
}