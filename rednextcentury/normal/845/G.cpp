#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > adj[1000000];
struct Base
{
	#define type int
	#define mx 28
	type d[mx+1];
	type p[mx+1];
	int sz;
	int cnt;
	Base()
	{
	    sz=0;
        cnt=0;
        for (int i=0;i<=mx;i++)
            d[i]=p[i]=0;
	}
	bool insert(type x)
	{
		int i;
		for(i=mx;~i;i--)
		{
			if(!(x&(1LL<<i))) continue;
			if(!d[i])
			{
				cnt++;
				d[i]=x;
				break;
			}
			x^=d[i];
		}
		if (x)
            p[sz++]=x;
		return x>0;
	}
	type query_max()
	{
		int i;
		type res=0;
		for(i=mx;~i;i--)
		{
			if ((res^d[i]) > res)res^=d[i];
		}
		return res;
	}
	type query_min(int x)
	{
		for(int i=mx;i>=0;i--)
		{
			if((x^d[i])<x) x=x^d[i];
		}
		return x;
	}
} base;
bool vis[1000000];
int path[1000000];
void dfs(int v)
{
    vis[v]=1;
    for (auto p:adj[v])
    {
        int u = p.first;
        int w = p.second;
        if (vis[u]) {
            base.insert(path[u]^path[v]^w);
            continue;
        }
        path[u]=path[v]^w;
        dfs(u);
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dfs(1);
    cout<<base.query_min(path[n])<<endl;
}