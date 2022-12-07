#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=2e5+50;
int n,m,top=0;
int d[N],stk[N],vis[N],ins[N];
vector<int> e[N],s[N];
void dfs(int x)
{
	vis[x]=ins[x]=1;
	for(int v:e[x])
	{
		if(!ins[v]) 
		{
			d[v]++;s[x].pb(v);
		}
		if(!vis[v]) dfs(v);
	}
	ins[x]=0;
}
int qry(int x,int y)
{
	int ret;
	printf("? %d %d\n",x,y);fflush(stdout);
	scanf("%d",&ret);
	return ret;
}
int main()
{
	int i,x,y,o,u,v;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++) 
	{
		scanf("%d%d",&u,&v);e[u].pb(v);
	}
	for(i=1;i<=n;i++) if(!vis[i]) dfs(i);
	for(i=1;i<=n;i++) if(!d[i]) stk[++top]=i;
	while(top>1)
	{
		x=stk[top];y=stk[top-1];top-=2;
		o=qry(x,y);
		if(!o) swap(x,y);
		for(int v:e[y])
		{
			if((--d[v])==0) stk[++top]=v;
		}
		stk[++top]=x;
	}
	printf("! %d",stk[1]);fflush(stdout);
	return 0;
}