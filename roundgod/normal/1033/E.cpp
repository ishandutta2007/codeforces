#include<bits/stdc++.h>
#define MAXN 605
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
bool used[MAXN];
vector<int> G[MAXN];
int color[MAXN],fa[MAXN];
vector<int> cycle;
void dfs(int v,int p,int c)
{
    color[v]=c; fa[v]=p;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v,-c);
    }
}
int query_edges(vector<int> &v)
{
    if(v.size()<=1) return 0;
    printf("? %d\n",(int)v.size());
    fflush(stdout);
    for(auto x:v) printf("%d ",x);
    printf("\n");
    fflush(stdout);
    int x;
    scanf("%d",&x);
    return x;
}
int query_cut(vector<int> &v1,vector<int> &v2,int save1=-1,int save2=-1)
{
    vector<int> all=v1;
    for(auto x:v2) all.push_back(x);
    return query_edges(all)-(save1==-1?query_edges(v1):save1)-(save2==-1?query_edges(v2):save2);
}
int binary_search(vector<int> &v1,vector<int> &v2)
{
    vector<int> tmp=v1;
    int save=query_edges(v2);
    while(tmp.size()>1)
    {
        int mid=(int)tmp.size()/2;
        vector<int> tmp2;
        for(int i=0;i<mid;i++)
            tmp2.push_back(tmp[i]);
        if(query_cut(tmp2,v2,-1,save)) tmp=tmp2;
        else                     
        {
            tmp2.clear();
            for(int i=mid;i<(int)tmp.size();i++) tmp2.push_back(tmp[i]);
            tmp=tmp2;
        }
    }
    return tmp[0];
}
P find_edge(vector<int> &v1,vector<int> &v2)
{
    int u=binary_search(v1,v2);
    vector<int> tmp; tmp.push_back(u);
    int v=binary_search(v2,tmp);
    return P(u,v);
}
P find_internal(vector<int> &v)
{
    assert(v.size()>1);
    if(v.size()==2) return P(v[0],v[1]);
    vector<int> v1,v2;
    int mid=(int)v.size()/2;
    for(int i=0;i<mid;i++) v1.push_back(v[i]);
    for(int i=mid;i<v.size();i++) v2.push_back(v[i]);
    if(query_edges(v1)) return find_internal(v1);
    else if(query_edges(v2)) return find_internal(v2);
    else return find_edge(v1,v2);
}
void bipartite(vector<int> &L,vector<int> &R)
{
    printf("Y %d\n",(int)L.size());
    for(auto x:L) printf("%d ",x);
    printf("\n");
    fflush(stdout);
    exit(0);
}
void get_path(int u,int v)
{
    dfs(u,0,-1);
    int now=v;
    while(now!=u)
    {
        cycle.push_back(now);
        now=fa[now];
    }
    cycle.push_back(u);
}
void have_cycle()
{
    printf("N %d\n",(int)cycle.size());
    for(auto x:cycle) printf("%d ",x);
    printf("\n");
    fflush(stdout);
    exit(0);
}
int main()
{
    scanf("%d",&n);
    memset(used,false,sizeof(used));
    used[1]=true;
    for(int i=2;i<=n;i++)
    {
        vector<int> v1,v2;
        for(int j=1;j<=n;j++) if(used[j]) v1.push_back(j); else v2.push_back(j);
        P p=find_edge(v1,v2);
        G[p.F].push_back(p.S); G[p.S].push_back(p.F);
        used[p.S]=true;
    }
    dfs(1,0,-1);
    vector<int> L; vector<int> R;
    for(int i=1;i<=n;i++) if(color[i]==-1) L.push_back(i); else R.push_back(i);
    if(!query_edges(L)&&(!query_edges(R))) bipartite(L,R);
    else if(query_edges(L))
    {
        P p=find_internal(L);
        get_path(p.F,p.S);
        have_cycle();
    }
    else 
    {
        P p=find_internal(R);
        get_path(p.F,p.S);
        have_cycle();
    }
    return 0;
}