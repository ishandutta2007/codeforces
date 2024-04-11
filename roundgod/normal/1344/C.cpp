#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
bool f;
int color[MAXN];
vector<int> G[MAXN],rG[MAXN];
string ans;
void dfs_visit(int v)
{
	color[v]=1;
	for(int i=0;i<(int)G[v].size();i++)
	{
		int to=G[v][i];
		if(color[to]==0) dfs_visit(to);
        else if(color[to]==1) f=false;
	}
	color[v]=2;
}
bool vis[2][MAXN];
void dfs(int v)
{
    vis[0][v]=true;
    for(auto to:G[v])
    {
        if(!vis[0][to]) dfs(to);
    }
}
void rdfs(int v)
{
    vis[1][v]=true;
    for(auto to:rG[v])
    {
        if(!vis[1][to]) rdfs(to);
    }
}
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        rG[v].push_back(u);
    }
    f=true;
    for(int i=1;i<=n;i++)
		if(color[i]==0)
			dfs_visit(i);
    if(!f) puts("-1");
    else
    {
        ans="";
        int cnt=0;
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            if(vis[0][i]||vis[1][i]) ans+="E";
            else 
            {
                ans+="A"; cnt++;
            }
            if(!vis[0][i]) dfs(i); 
            if(!vis[1][i]) rdfs(i);
        }
        printf("%d\n",cnt);
        cout<<ans<<endl;
    }
    return 0;
}