#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100005
using namespace std;
int n;
double ans;
int to[N<<1],hd[N<<1],lk[N],cnt;
bool vis[N];
void ad(int u,int v)
{to[++cnt]=v,hd[cnt]=lk[u],lk[u]=cnt;}
void dfs(int x,double p,int d)
{
	vis[x]=1;
	int son=0;
	for(int i=lk[x];i;i=hd[i])
	if(!vis[to[i]])son++;
	if(!son)ans+=p*d;
	else for(int i=lk[x];i;i=hd[i])
	if(!vis[to[i]])
	dfs(to[i],p/son,d+1);
} 
int u,v;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	scanf("%d%d",&u,&v),
	ad(u,v),ad(v,u);
	dfs(1,1.0,0);
	printf("%.8lf",ans);
}