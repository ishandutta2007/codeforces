#include <iostream>
#include <vector>
using namespace std;
const int N = 150000+10;
vector<int> g[N];
int n,par[N];

int find(int x) {
    if(par[x] == x)
        return x;
    return par[x] = find(par[x]);
}
void dfs(int u){
    printf("%d ", u);
    for(auto v: g[u]) {
        dfs(v);
    }
}

int main() {
    for(int i=1;i<N;i++) par[i]=i;
    scanf("%d",&n);
    int rt=0;
    for(int i=2;i<=n;i++){
        int u,v; scanf("%d%d",&u,&v);
        g[find(v)].push_back(find(u));
        //printf("%d->%d\n", find(v), find(u));
        par[find(u)]=(rt=find(v));
    }
    dfs(rt);
}
/*
1-2
1-4
2-3



*/