#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)

using namespace std;
const int N=605,M=205,INF=1000000000;
int n,k,V,E,a[N],cnt,h[N+M],cur[N+M],dis[N+M],g[N+M];
int S[N][N],u,v,c,s,t,p[M];
struct edge{int v,f,n;} e[N*M*2];

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
	e[cnt]=(edge){v,1,h[u]},h[u]=cnt++;
	e[cnt]=(edge){u,0,h[v]},h[v]=cnt++;
}

int isap(int x,int rt)
{
	if(x==t) return rt;
	int sum=0;
	for(int i=cur[x]; i!=-1; i=e[i].n)
		if(e[i].f && dis[x]==dis[e[i].v]+1)
		{
			int f=isap(e[i].v,min(rt-sum,e[i].f));
			e[i].f-=f,e[i^1].f+=f,sum+=f;
			if(cur[x]=i,sum==rt || dis[s]>=t) return sum;
		}
	if(!(--g[dis[x]++])) dis[s]=t;
	++g[dis[x]],cur[x]=h[x];
	return sum;
}

bool check(int lim)
{
	memset(h,-1,sizeof(h)),cnt=0;
	s=V+n+1,t=s+1;
	rep(i,1,n) addedge(s,i);
	rep(i,1,V) addedge(n+i,t);
	rep(i,1,n) rep(j,1,V) if(S[p[i]][j]<=lim) addedge(i,n+j);
	memset(g,0,sizeof(g));
	memset(dis,0,sizeof(dis));
	memcpy(cur,h,sizeof(h));
	int ret=0;
	for(g[0]=t; dis[s]<t; ret+=isap(s,INF));
	return ret>=k;
}

int main()
{
	V=getint(),E=getint(),n=getint(),k=getint();
	rep(i,1,n) p[i]=getint();
	rep(i,1,V) rep(j,1,V) if(i!=j) S[i][j]=INF;
	rep(i,1,E) u=getint(),v=getint(),c=getint(),S[u][v]=S[v][u]=min(S[u][v],c);
	rep(k,1,V) rep(i,1,V) rep(j,1,V) S[i][j]=min(S[i][j],S[i][k]+S[k][j]);
	int l=0,r=1731311;
	while(l<=r) check(mid)?r=mid-1:l=mid+1;
	if((++r)>1731311) puts("-1");
	else printf("%d\n",r);
	return 0;
}