#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
std::mt19937 rnd(time(0));
inline int sj(int n)
{
	unsigned int x=rnd();
	return x%n+1;
}
#define rand fst
template<typename typC> void read(register typC &x)
{
	register int c=getchar(),fh=1;
	while ((c<48)||(c>57))
	{
		if (c=='-') {c=getchar();fh=-1;break;}
		c=getchar();
	}
	x=c^48;c=getchar();
	while ((c>=48)&&(c<=57))
	{
		x=x*10+(c^48);
		c=getchar();
	}
	x*=fh;
}
template<typename typC> void write(register typC x)
{
	if (x<0) putchar('-'),x=-x;
	static int st[100];
	register int tp=1;
	register typC y;st[1]=x%10;x/=10;
	while (x) y=x/10,st[++tp]=x-y*10,x=y;++tp;
	while (--tp) putchar(st[tp]|48);
}
template<typename typC> void write(register typC *a,register int num)
{
	for (register int i=1;i<=num;i++) write(a[i]),putchar(i==num?10:32);
}
#define space(x) write(x),putchar(32)
#define enter(x) write(x),putchar(10)
const int N=2e5+2,M=1e7+2,p=998244353;
inline void inc(register int &x,const int y)
{
	if ((x+=y)>=p) x-=p;
}
inline void dec(register int &x,const int y)
{
	if ((x-=y)<0) x+=p;
}
inline int ksm(register int x,register int y)
{
	register int r=1;
	while (y)
	{
		if (y&1) r=(ll)r*x%p;
		x=(ll)x*x%p;
		y>>=1;
	}
	return r;
}
char s[N];
bool ed[M];
int a[N],b[N],mn[M],ss[M>>2];
int T,n,m,c,i,j,k,x,y,gs,z,ans,la;
int main()
{
	for (i=2;i<M;i++)
	{
		if (!mn[i]) ss[++gs]=i,mn[i]=i;
		for (j=1;j<=gs&&i*ss[j]<M;j++)
		{
			mn[i*ss[j]]=ss[j];
			if (i%ss[j]==0) break;
		}
	}
	T=1;read(T);
	while (T--)
	{
		read(n);read(m);
		for (i=1;i<=n;i++)
		{
			read(a[i]);
			x=a[i];
			while (x>1)
			{
				y=mn[x];x/=y;z=1;
				while (x%y==0)
				{
					++z;if (z==2) z=0,a[i]/=(y*y);
					x/=y;
				}
			}//printf("%d\n",a[i]);
		}ans=0;
		for (i=1;i<=n;i=j+1)
		{
			j=i;ed[a[i]]=1;
			while (j<n&&!ed[a[j+1]]) ed[a[++j]]=1;
			++ans;for (int k=i;k<=j;k++) ed[a[k]]=0;
		}printf("%d\n",ans);
	}
}