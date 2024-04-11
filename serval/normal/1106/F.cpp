#include <cstdio>
using namespace std;
const int N=105;
const int mod=998244353;
const int P=mod-1;
int k,b[N];
int t[N][N],tt[N][N];
int f[N],tf[N];
int n,m,ex;
long long x,y,d;
const int hsz=311100;
const long long hmod=311021;
const long long mrt=31596;
const int g=3;
int val[hsz],mln[hsz];
bool used[hsz];
inline void __usr_ins(int v,int p)
{
	static int h,j;
	h=v%hmod;
	j=1;
	while (used[h]&&val[h]!=v)
	{
		h=(1ll*h+1ll*j*j)%mod;
		j++;
	}
	used[h]=1;
	val[h]=v;
	mln[h]=p;
}
inline int __usr_qry(int v)
{
	static int h,j;
	h=v%hmod;
	j=1;
	while (used[h]&&val[h]!=v)
	{
		h=(1ll*h+1ll*j*j)%mod;
		j++;
	}
	if (used[h])
		return mln[h];
	return -1;
}
inline int __usr_fpw (int p,int e)
{
	if (e==0)
		return 1;
	long long ret=__usr_fpw(p,e>>1);
	ret=ret*ret%mod;
	if (e&1)
		ret=ret*p%mod;
	return ret;
}
inline int __usr_inv (int p)
{
	return __usr_fpw(p,mod-2);
}
inline int __usr_log(int p)
{
	static int i,j,res;
	j=1;
	for (int i=0;i<mrt;i++)
	{
		__usr_ins(j,i);
		j=1ll*j*g%mod;
	}
	res=0;
	j=__usr_inv(j);
	for (int i=0;i<=mrt;i++)
	{
		if (__usr_qry(p)!=-1)
		{
			res=(res+__usr_qry(p))%P;
			return res;
		}
		p=(long long)p*j%mod;
		res=(res+mrt)%P;
	}
	return -1;
}
int exgcd(int a,int b,long long &x,long long &y)
{
	if (!b)
	{
		x=1;
		y=0;
		return a;
	}
	int ret=exgcd(b,a%b,x,y);
	int t=x;
	x=y;
	y=t-1ll*a/b*y;
	return ret;
}
int gcd(int a,int b)
{
	if (a%b==0)
		return b;
	return gcd(b,a%b);
}
int main()
{
	scanf("%d",&k);
	for (int i=1;i<=k;i++)
		scanf("%d",&b[i]);
	for (int i=1;i<k;i++)
		t[i+1][i]=1;
	for (int i=1;i<=k;i++)
		t[i][k]=b[k+1-i];
	f[k]=1;
	scanf("%d%d",&n,&m);
	n-=k;
	while (n)
	{
		if (n&1)
		{
			for (int i=1;i<=k;i++)
				tf[i]=0;
			for (int i=1;i<=k;i++)
				for (int j=1;j<=k;j++)
					tf[j]=(tf[j]+1ll*f[i]*t[i][j])%P;
			for (int i=1;i<=k;i++)
				f[i]=tf[i];
		}
		n>>=1;
		if (n)
		{
			for (int i=1;i<=k;i++)
				for (int j=1;j<=k;j++)
					tt[i][j]=0;
			for (int i=1;i<=k;i++)
				for (int j=1;j<=k;j++)
					for (int x=1;x<=k;x++)
						tt[i][j]=(tt[i][j]+1ll*t[i][x]*t[x][j])%P;
			for (int i=1;i<=k;i++)
				for (int j=1;j<=k;j++)
					t[i][j]=tt[i][j];
		}
	}
	ex=__usr_log(m);
	//f[k]*x==ex(mod P)
	if (ex%gcd(f[k],P)==0)
	{
		d=exgcd(P,f[k],x,y);
		d=1ll*y*ex/d;
		d%=P;
		if (d<0)
			d+=P;
		printf("%d\n",__usr_fpw(g,d));
	}
	else
		printf("-1\n");
	return 0;
}