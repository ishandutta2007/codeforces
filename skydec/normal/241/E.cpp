#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
typedef long long LL;
typedef double db;
#define MAXN 5100
struct ed
{
	int u,v;
}e[MAXN];
int n,m;
int go1[MAXN];int go2[MAXN];
void dfs1(int x){
	if(go1[x])return;go1[x]=1;
	rep(i,1,m)if(e[i].u==x)dfs1(e[i].v);
}
void dfs2(int x){
	if(go2[x])return;go2[x]=1;
	rep(i,1,m)if(e[i].v==x)dfs2(e[i].u);
}
int dis[MAXN];
int main()
{
	scanf("%d%d",&n,&m);memset(dis,0x00,sizeof dis);
	rep(i,1,m)scanf("%d%d",&e[i].u,&e[i].v);
	dfs1(1);dfs2(n);
	rep(i,0,n+m)
	rep(j,1,m)if(go1[e[j].u]&&go2[e[j].v]){
		dis[e[j].v]=min(dis[e[j].u]+2,dis[e[j].v]);
		dis[e[j].u]=min(dis[e[j].v]-1,dis[e[j].u]);
	}
	rep(i,1,m)if(go1[e[i].u]&&go2[e[i].v])
	if(dis[e[i].v]-dis[e[i].u]<1||dis[e[i].v]-dis[e[i].u]>2)
	{
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	rep(i,1,m)if(go1[e[i].u]&&go2[e[i].v])printf("%d\n",dis[e[i].v]-dis[e[i].u]);
	else printf("%d\n",1);
	return 0;
}