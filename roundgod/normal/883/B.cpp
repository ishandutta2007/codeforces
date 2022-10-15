#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,x,rk[MAXN];
vector<int> G[MAXN];
vector<P> u[MAXN];
int color[MAXN],l[MAXN],r[MAXN];
bool used[MAXN];
deque<int> order;
set<P> s;
bool dfs_visit(int v)
{
	color[v]=1;
	bool f=true;
	for(int i=0;i<G[v].size();i++)
	{
		int to=G[v][i];
		if(color[to]==0) f|=dfs_visit(to);
		if(color[to]==1) return false;
	}
	color[v]=2;
	order.push_front(v);
	return f;
}
bool toposort()
{
	memset(color,0,sizeof(color));
	for(int i=1;i<=n;i++)
		if(color[i]==0)
			if(!dfs_visit(i)) return false;
	return true;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x!=0) l[i]=r[i]=x;
		else
		{
			r[i]=k;
			l[i]=1;
		}
	}
	for(int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
	}
	if(!toposort()) {puts("-1"); return 0;}
	memset(used,false,sizeof(used));
	for(int i=0;i<n;i++)
	{
		int v=order[i];
		for(int j=0;j<G[v].size();j++)
		{
			int to=G[v][j];
			r[to]=min(r[to],r[v]-1);
		}
	}
	for(int i=n-1;i>=0;i--)
	{
		int v=order[i];
		for(int j=0;j<G[v].size();j++)
		{
			int to=G[v][j];
			l[v]=max(l[to]+1,l[v]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(l[i]>r[i])
		{
			puts("-1");
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
        u[l[i]].push_back(P(r[i],i));
   // for(int i=1;i<=n;i++)
   // 	printf("%d %d\n",l[i],r[i]);
    for(int i=1;i<=k;i++)
    {
        for(auto it:u[i])
            s.insert(it);
        if(!s.size())
        {
            puts("-1");
            return 0;
        }
        auto val=*s.begin();
        rk[val.second]=i;
        s.erase(s.begin());
        while((val=*s.begin()).first==i)
        {
            rk[val.second]=i;
            s.erase(s.begin());
        }
    }
    for(int i=1;i<=n;i++)
    	printf("%d ",rk[i]);
	return 0;
}