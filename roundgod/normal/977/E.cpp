#include<bits/stdc++.h>
#define MAXV 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int V,E;
vector<int> G[MAXV];
vector<int> rG[MAXV];
vector<int> vs;
bool used[MAXV];
int cmp[MAXV],deg[MAXV];
bool is_cycle[MAXV];
void add_edge(int from,int to)
{
    G[from].push_back(to);
    rG[to].push_back(from);
}
void dfs(int v)
{
    used[v]=true;
    for(int i=0;i<G[v].size();i++)
        if(!used[G[v][i]]) dfs(G[v][i]);
    vs.push_back(v);
}
void rdfs(int v,int k)
{
    used[v]=true;
    cmp[v]=k;
    for(int i=0;i<rG[v].size();i++)
        if(!used[rG[v][i]]) rdfs(rG[v][i],k);
}
int scc()
{
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=1;v<=V;v++)
    {
        if(!used[v]) dfs(v);
    }
    int k=0;
    memset(used,0,sizeof(used));
    for(int i=vs.size()-1;i>=0;i--)
    {
        if(!used[vs[i]]) rdfs(vs[i],k++);
    }
    return k;
}
int main()
{
	scanf("%d%d",&V,&E);
	memset(deg,0,sizeof(deg));
	for(int i=1;i<=E;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);add_edge(v,u);
		deg[u]++;deg[v]++;
	}
	int p=scc();
	memset(is_cycle,true,sizeof(is_cycle));
	for(int i=1;i<=V;i++)
		if(deg[i]!=2) is_cycle[cmp[i]]=false;
	int cnt=0;
	for(int i=0;i<p;i++)
		if(is_cycle[i]) cnt++;
	printf("%d\n",cnt);
	return 0;
}