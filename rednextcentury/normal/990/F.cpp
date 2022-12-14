#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 20
int par[200006][21];
vector<pair<int,int> > E;
vector<int> ret;
bool vis[1000000];
vector<pair<int,int> > padj[1000000];
vector<pair<int,int> > adj[1000000];
bool taken[1000000];
int dep[1000000];
void pre(int v,int p=0)
{
    par[v][0]=p;
    vis[v]=1;
    for (auto u:padj[v]){
        if (vis[u.first])continue;
        dep[u.first]=dep[v]+1;
        taken[u.second]=1;
        pre(u.first,v);
    }
}
int lca(int u,int v)
{
    if (dep[u]<dep[v])swap(u,v);
    int need = dep[u]-dep[v];
    for (int i=0;i<M;i++) {
        if ((1<<i)&need)u=par[u][i];
    }
    if (u==v)return u;
    for (int i=M-1;i>=0;i--){
        if (par[u][i]==0)continue;
        if (par[u][i]!=par[v][i])u=par[u][i],v=par[v][i];
    }
    return par[u][0];
}
int add[1000000];
void dfs(int v,int p)
{
    for (auto u:adj[v]){
        if (u.first==p)continue;
        dfs(u.first,v);
        ret[u.second]=add[u.first];
        add[v]+=add[u.first];
    }
}
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    scanf("%d",&n);
    set<pair<int,int> > s;
    for (int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        s.insert({x,i});
    }
    if (n==1) {
        if ((*s.begin()).first==0) {
            printf("Possible\n");
        } else {
            printf("Impossible\n");
        }
        return 0;
    }
    int m;
    scanf("%d",&m);
    for (int i=0;i<m;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        padj[u].push_back({v,i});
        padj[v].push_back({u,i});
        E.push_back({u,v});
        ret.push_back(0);
    }
    pre(1);
    for (int i=0;i<E.size();i++){
        if (taken[i]){
            adj[E[i].first].push_back({E[i].second,i});
            adj[E[i].second].push_back({E[i].first,i});
        }
    }
    for (int i=1;i<M;i++)
        for (int j=1;j<=n;j++)
            par[j][i]=par[par[j][i-1]][i-1];
    while(1){
        auto L = *s.begin();
        auto R = *(--s.end());
        s.erase(s.begin());
        s.erase(--s.end());
        if (L.first>=0 || R.first<=0){
            s.insert(L);s.insert(R);

            break;
        }
        //if (R.first<=0)break;
        int need = min(-L.first,R.first);
        int u=L.second,v=R.second;
        //int l = lca(u,v);
        add[v]+=need;
        add[u]-=need;
        L.first+=need;
        R.first-=need;
        s.insert(L);s.insert(R);
    }
    if ((*(--s.end())).first!=0 || (*s.begin()).first!=0){
        printf("Impossible\n");
        return 0;
    }
    dfs(1,0);
    printf("Possible\n");
    for (int i=0;i<E.size();i++) {
        if (par[E[i].second][0]!=E[i].first)ret[i]=-ret[i];
        printf("%d\n",ret[i]);
    }
}