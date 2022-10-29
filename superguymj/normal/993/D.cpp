#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<cmath>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=205;
const double INF=1e16,eps=1e-6;
int n,id[N],a[N],b[N];
double c[N],ans,f[N][N][N],g[N][N];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

bool check(double x)
{
	rep(i,1,n) c[i]=a[i]-b[i]*x;
	rep(i,0,n) rep(j,0,n) rep(k,0,n) f[i][j][k]=INF;
	f[0][0][0]=0;
	rep(i,0,n-1)
	{
		int x=id[i+1];
		if(i && a[id[i]]!=a[id[i+1]])
		{
			rep(j,0,n) rep(k,0,n) g[j][k]=f[i][j][k],f[i][j][k]=INF;
			rep(j,0,n) rep(k,0,n) f[i][j+k][0]=min(f[i][j+k][0],g[j][k]);
		}
		rep(j,0,n)
			rep(k,0,n)
			{
				f[i+1][j][k+1]=min(f[i+1][j][k+1],f[i][j][k]+c[x]);
				if(j) f[i+1][j-1][k]=min(f[i+1][j-1][k],f[i][j][k]);
			}
	}
	ans=INF;
	rep(i,0,n) rep(j,0,n) ans=min(ans,f[n][i][j]);
	return ans+eps<0;
}

bool cmp(int x,int y)
{
	return a[x]>a[y];
}

int main()
{	
	n=getint();
	rep(i,1,n) a[i]=getint();
	rep(i,1,n) b[i]=getint();
	rep(i,1,n) id[i]=i;
	sort(id+1,id+1+n,cmp);
	double l=0,r=100000000;

//	double l=0,r=2;

	while(l+eps<r)
	{
		double mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}
	l=l*1000;
	LL GG=(LL)l;
	if((l-=GG)>=(1e-2)) ++GG;
	printf("%lld\n",GG);
	return 0;
}