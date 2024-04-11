#include<bits/stdc++.h>
#define P(x,y) make_pair(x,y)
using namespace std;
const int MX=(1<<20);
class TwoSAT{
    public:
    int n;
    vector < vector<int> > g, gt;
    vector<bool> used;
    vector<int> order, comp;
    void dfs1 (int v) {
        used[v] = true;
        for (size_t i=0; i<g[v].size(); ++i) {
            int to = g[v][i];
            if (!used[to])
                dfs1 (to);
        }
        order.push_back (v);
    }
    void dfs2 (int v, int cl) {
        comp[v] = cl;
        for (size_t i=0; i<gt[v].size(); ++i) {
            int to = gt[v][i];
            if (comp[to] == -1)
                dfs2 (to, cl);
        }
    }
    bool Satisfable(vector < int > &sol){
        sol.resize(n/2);
        sol.clear();
        for(int i = 0 ; i < n ; i++)
           if (!used[i])
                dfs1 (i);
        for (int i=0, j=0; i<n; ++i) {
            int v = order[n-i-1];
            if (comp[v] == -1) dfs2 (v, j++);
        }
        for(int i = 0 ; i < n ; i++)
            if (comp[i] == comp[i^1])
                return 0;
        for(int i = 0 ; i < n ; i+=2){
            int ans = comp[i] > comp[i^1] ? i : i^1;
            sol.push_back(ans%2);
        }
        return 1;
    }
    void init(int N){
        n = N * 2;
        used.clear(); order.clear(); comp.clear();
        g.resize(n);
        gt.resize(n);
        used.assign (n, false);
        comp.assign (n, -1);
    }
    void imply(int a , int na ,int b , int nb){
        // na :: 0 variable is false , 1 variable is true
        // pass variables 1 indexed
        a--; b--;
        a*=2 , b*=2;
        a += na , b +=nb;
        g[a].push_back(b);
        gt[b].push_back(a);
        g[b^1].push_back(a^1);
        gt[a^1].push_back(b^1);
    }
}G;
int n,p,M,m;
int getGreaterThan(int x){return p+x;}
int getLessThan(int x){return p+M+x;}
int main()
{
    scanf("%d%d%d%d",&n,&p,&M,&m);
    G.init(p+M+M);
    for (int i=1;i<=M;i++)
    {
        if (i>1)
        {
            G.imply(getLessThan(i),0,getLessThan(i-1),0);
            G.imply(getLessThan(i-1),1,getLessThan(i),1);
            G.imply(getGreaterThan(i),1,getLessThan(i-1),0);
        }
        if (i<M)
        {
            G.imply(getGreaterThan(i),0,getGreaterThan(i+1),0);
            G.imply(getGreaterThan(i+1),1,getGreaterThan(i),1);
            G.imply(getGreaterThan(i+1),1,getLessThan(i),0);
        }
    }
    for (int i=1;i<=n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G.imply(u,0,v,1);
        G.imply(v,0,u,1);
    }
    for (int i=1;i<=p;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        G.imply(i,1,getLessThan(r),1);
        G.imply(i,1,getGreaterThan(l),1);
    }
    for (int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G.imply(u,1,v,0);
        G.imply(v,1,u,0);
    }
    vector<int> sol;
    bool ok = G.Satisfable(sol);
    if (!ok){
        puts("-1");
        return 0;
    }
    int ans=-1;
    for (int i=1;i<=M;i++)
        if (sol[getGreaterThan(i)-1]==1)
            ans=i;
    vector<int> ret;
    for (int i=1;i<=p;i++)
        if (sol[i-1]==1)
            ret.push_back(i);
    printf("%d %d\n",(int)ret.size(),ans);
    for(auto x:ret)printf("%d ",x);
}