#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=55;
int n,h[N],cnt,siz[N];
double f[N][N],g[N],F[N],c[N][N];
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

void dfs(int x,int fa)
{
	f[x][0]=1,siz[x]=0;
	for(int i=h[x],v; i!=-1; i=e[i].n)
		if((v=e[i].v)!=fa)
		{
	
			dfs(v,x);
			rep(j,0,siz[v])
			{
				g[j]=j?f[v][j-1]*j:0;
				rep(k,j,siz[v]-1) g[j]+=f[v][k]*0.5;
			}
			rep(j,0,siz[x]+siz[v]) F[j]=0;
			rep(j,0,siz[x]) rep(k,0,siz[v]) F[j+k]+=f[x][j]*g[k]*c[j+k][j]*c[siz[x]+siz[v]-j-k][siz[x]-j];
			rep(j,0,siz[x]+siz[v]) f[x][j]=F[j];
			siz[x]+=siz[v];
		}
	++siz[x];
}

int main()
{
	n=getint();
	memset(h,-1,sizeof(h));
	rep(i,1,n-1) addedge(getint(),getint());
	rep(i,0,n) c[i][i]=c[i][0]=1;
	rep(i,1,n) rep(j,1,i-1) c[i][j]=c[i-1][j]+c[i-1][j-1];
	double flv=1;
	rep(i,1,n-1) flv*=i;
	rep(i,1,n)
	{
		dfs(i,0);
		printf("%.10lf\n",f[i][0]/flv);
	}
	return 0;
}