#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=2e5+50;
int n,D;
int fa[N],siz[N],son[N],det[N];
vector<int> e[N];
int qryd(int x)
{
	int ret;
	printf("d %d\n",x);fflush(stdout);
	scanf("%d",&ret);
	return ret;
}
int qrys(int x)
{
	int ret;
	printf("s %d\n",x);fflush(stdout);
	scanf("%d",&ret);
	return ret;
}
void dfs(int x,int nf)
{
	fa[x]=nf;det[x]=det[nf]+1;
	siz[x]=1;
	for(int v:e[x])
	{
		if(v==nf) continue;
		dfs(v,x);
		if(siz[v]>siz[son[x]]) son[x]=v;
		siz[x]+=siz[v];
	}
}
void solve(int pos)
{
	int x,dis,len;
	for(x=pos;son[x]>0;x=son[x]);
	dis=qryd(x);
	len=(D+det[x]-dis)>>1;
	while(det[x]>len) x=fa[x];
	if(D==len) 
	{
		printf("! %d",x);
		return ;
	}
	solve(qrys(x));
}
int main()
{
	//freopen("a.in","r",stdin);
	int i,u,v;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		e[u].pb(v);e[v].pb(u);
	}
	dfs(1,0);
	D=qryd(1)+1;
	if(D==1)
	{
		puts("! 1");
		return 0;
	}
	solve(1);
	return 0;
}