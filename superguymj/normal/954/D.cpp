#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=4005;
int n,m,s,t,head,tail,q[N],len,u,v,ans,h[N],cnt,dis[2][N];
struct edge{int v,n;} e[N<<1];

void addedge(int u,int v)
{
	e[cnt]=(edge){v,h[u]},h[u]=cnt++;
	e[cnt]=(edge){u,h[v]},h[v]=cnt++;
}

void bfs(int s,int tp)
{
	dis[tp][q[head=tail=0]=s]=0;
	while(head<=tail)
	{
		int x=q[head++];
		for(int i=h[x]; i!=-1; i=e[i].n)
			if(dis[tp][e[i].v]==-1) dis[tp][e[i].v]=dis[tp][x]+1,q[++tail]=e[i].v;
	}
}

int main()
{
	scanf("%d%d%d%d",&n,&m,&s,&t);
	memset(h,-1,sizeof(h));
	memset(dis,-1,sizeof(dis));
	rep(i,1,m) scanf("%d%d",&u,&v),addedge(u,v);
	bfs(s,0);
	bfs(t,1);
	len=dis[0][t];
	rep(i,1,n)
		rep(j,i+1,n)
			if(1+min(dis[0][i]+dis[1][j],dis[0][j]+dis[1][i])>=len) ++ans;
	printf("%d\n",ans-m);
	return 0;
}