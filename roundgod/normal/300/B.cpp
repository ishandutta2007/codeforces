#include<bits/stdc++.h>
#define MAXV 20000
using namespace std;
int n,m;
vector<int> G[MAXV];
vector<int> rG[MAXV];
vector<int> vs;
bool used[MAXV];
int cmp[MAXV];
vector<int> team[MAXV];
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
    for(int v=1;v<=n;v++)
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
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);add_edge(v,u);
	}
	int p=scc();
	int cnt1=0,cnt2=0,cnt3=0;
	for(int i=1;i<=n;i++)
		team[cmp[i]].push_back(i);
	for(int i=0;i<p;i++)
		sort(team[i].begin(),team[i].end());
	vector<int> team1,team2,team3;
	for(int i=0;i<p;i++)
	{
		if(team[i].size()>3) {puts("-1"); return 0;}
		if(team[i].size()==3) {team3.push_back(i); cnt3++;}
		if(team[i].size()==2) {team2.push_back(i); cnt2++;}
		if(team[i].size()==1) {team1.push_back(i); cnt1++;}
	}
	if(cnt1<cnt2) {puts("-1"); return 0;}
	for(int i=0;i<team3.size();i++)
		printf("%d %d %d\n",team[team3[i]][0],team[team3[i]][1],team[team3[i]][2]);
	for(int i=0;i<team2.size();i++)
	{
		int x=team[team2[i]][0];
		int y=team[team2[i]][1];
		int z=team[team1[i]][0];
		if(x>y) swap(x,y);
		if(x>z) swap(x,z);
		if(y>z) swap(y,z);
		printf("%d %d %d\n",x,y,z);
	}
	for(int i=team2.size();i<team1.size();i+=3)
	{
		int x=team[team1[i]][0];
		int y=team[team1[i+1]][0];
		int z=team[team1[i+2]][0];
		if(x>y) swap(x,y);
		if(x>z) swap(x,z);
		if(y>z) swap(y,z);
		printf("%d %d %d\n",x,y,z);
	}
    return 0;
}