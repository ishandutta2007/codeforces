#include <iostream>
#include <vector>
using namespace std;
const int N = 100000 + 10;
int n,par[N];vector<int> g[N]; 
double p[N],sum[N],ans=0;
double E=0,V=0;
void dfs(int u,int f) {
    par[u]=f;
    for(auto v: g[u]) if(v!=f) {
        dfs(v, u);
        sum[u] += p[v];
    }
    E = E + p[u] * sum[u];
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lf",&p[i]); p[i]=1-p[i];
        V += p[i];
    }
    for(int i=1;i<n;i++) {
        int u,v; scanf("%d%d",&u,&v); u++, v++;
        g[u].push_back(v); g[v].push_back(u);      
    }
    dfs(1,0); ans = V - E;
    //printf("%.8f %.8f\n", V, E);
    int q; scanf("%d",&q);
    while(q --) {
        int pos; double x;  
        scanf("%d%lf",&pos,&x); x=1-x; pos++;
        V -= p[pos]; sum[par[pos]] -= p[pos]; E -= p[pos]*sum[pos]; if(par[pos]) E -= p[pos]*p[par[pos]];
        p[pos]=x; 
        V += p[pos]; sum[par[pos]] += p[pos]; E += p[pos]*sum[pos]; if(par[pos]) E += p[pos]*p[par[pos]];
        printf("%.8f\n", V - E);
    }
}