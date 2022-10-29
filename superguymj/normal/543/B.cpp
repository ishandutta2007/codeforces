#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=3005;
bool vis[N];
int n,m,h[N],cnt,dis[N][N],s1,s2,t1,t2,l1,l2,ans,head,tail,q[N];
struct edge{int v,n;} e[N<<1];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void addedge(int u,int v)
{
	e[cnt]=(edge){v,h[u]},h[u]=cnt++;
	e[cnt]=(edge){u,h[v]},h[v]=cnt++;
}

void bfs(int x)
{
	memset(vis,0,sizeof(vis));
	vis[q[head=tail=0]=x]=1;
	while(head<=tail)
	{
		int u=q[head++];
		for(int i=h[u]; i!=-1; i=e[i].n)
			if(!vis[e[i].v])
				vis[q[++tail]=e[i].v]=1,dis[x][e[i].v]=dis[x][u]+1;
	}
}

int main()
{
	n=getint(),m=getint(),memset(h,-1,sizeof(h));
	rep(i,1,m) addedge(getint(),getint());
	rep(i,1,n)
	{
		rep(j,1,n) if(i!=j) dis[i][j]=10000000;
		bfs(i);
	}
	s1=getint(),t1=getint(),l1=getint(),s2=getint(),t2=getint(),l2=getint();
	if(dis[s1][t1]>l1 || dis[s2][t2]>l2) {puts("-1"); return 0;}
	ans=dis[s1][t1]+dis[s2][t2];
	rep(i,1,n)
		rep(j,1,n)
			if(dis[s1][i]+dis[i][j]+dis[j][t1]<=l1 && dis[s2][i]+dis[i][j]+dis[j][t2]<=l2)
				ans=min(ans,dis[s1][i]+dis[i][j]+dis[j][t1]+dis[s2][i]+dis[j][t2]);
	swap(s2,t2);
	rep(i,1,n)
		rep(j,1,n)
			if(dis[s1][i]+dis[i][j]+dis[j][t1]<=l1 && dis[s2][i]+dis[i][j]+dis[j][t2]<=l2)
				ans=min(ans,dis[s1][i]+dis[i][j]+dis[j][t1]+dis[s2][i]+dis[j][t2]);
	printf("%d\n",m-ans);
	return 0;
}