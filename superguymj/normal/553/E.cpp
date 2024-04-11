#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<cmath>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const double pi=acos(-1);
const int N=55,M=105,K=20005;
bool vis[N];
int n,m,t,lim,len,u,v,bin[K<<2];
int cnt,h[N],dis[N][N],head,tail,q[1000000];
double f[N][K],p[M][K],sum[M][K];
struct point
{
	double x,y;
	point operator + (point a)
	{
		return (point){x+a.x,y+a.y};	
	}
	point operator - (point a)
	{
		return (point){x-a.x,y-a.y};
	}
	point operator * (point a)
	{
		return (point){x*a.x-y*a.y,x*a.y+y*a.x};	
	}
} a[K<<2],b[K<<2];
struct edge{int v,c,n;} e[M];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;	
	return x;
}

void FFT(point a[],int len,int tp)
{
	rep(i,0,len-1) if(i<bin[i]) swap(a[i],a[bin[i]]);
	for(int i=1; i<len; i<<=1)
	{
		point wn=(point){cos(pi/i),tp*sin(pi/i)};
		for(int j=0; j<len; j+=i<<1)
		{
			point w=(point){1,0},x,y;
			rep(k,0,i-1)
			{
				x=a[j+k],y=a[i+j+k]*w,w=w*wn;
				a[j+k]=x+y,a[i+j+k]=x-y;
			}
		}
	}
	if(tp==-1) rep(i,0,len-1) a[i].x/=len;
}

void addedge(int u,int v,int c)
{
	e[cnt]=(edge){v,c,h[u]},h[u]=cnt++;
}

void spfa()
{
	rep(i,1,n-1)
		rep(j,0,t)
			f[i][j]=dis[i][n]+lim;
	vis[q[head=tail=0]=n]=1;
	while(head<=tail)
	{
		int u=q[head++];
		for(int i=h[u]; i!=-1; i=e[i].n)
		{
			rep(j,0,len-1) a[j]=b[j]=(point){0,0};
			rep(j,0,t) a[j].x=f[u][j],b[j].x=p[i][j];
			FFT(a,len,1),FFT(b,len,1);
			rep(j,0,len-1) a[j]=a[j]*b[j];
			FFT(a,len,-1);
			rep(j,0,t)
				if(e[i].c+a[j].x+(1-sum[i][j])*(dis[u][n]+lim)<f[e[i].v][j])
					if(f[e[i].v][j]=e[i].c+a[j].x+(1-sum[i][j])*(dis[u][n]+lim),!vis[e[i].v])
						vis[q[++tail]=e[i].v]=1;
		}
		vis[u]=0;
	}
}

int main()
{
	n=getint(),m=getint(),t=getint(),lim=getint();
	memset(dis,60,sizeof(dis)),memset(h,-1,sizeof(h));
	rep(i,1,n) dis[i][i]=0;
	while(m--)
	{
		u=getint(),v=getint(),dis[u][v]=getint();
		addedge(v,u,dis[u][v]);
		rep(i,1,t) p[cnt-1][i]=(double)getint()/100000;
		rep(i,1,t) sum[cnt-1][i]=sum[cnt-1][i-1]+p[cnt-1][i];
	}
	rep(k,1,n)
		rep(i,1,n)
			rep(j,1,n)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(len=1; len<=t*2; len<<=1);
	rep(i,0,len-1) bin[i]=bin[i>>1]>>1|((i&1)*(len>>1));
	spfa();
	printf("%.10lf\n",f[1][t]);
	return 0;
}