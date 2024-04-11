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
const int N=1e7+2,M=1e6+2,p=998244353;
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
ll d[N];
int ss[N],mn[N],ys[N];
int T,n,m,c,i,j,k,x,y,z,ans,gs,la;
int main()
{
	n=1e7;d[1]=1;
	for (i=2;i<=n;i++)
	{
		//printf("%d\n",i);
		if (!d[i]) ss[++gs]=i,d[i]=i+1,mn[i]=i;
		for (j=1;j<=gs&&(k=i*ss[j])<=n;j++)
		{
			//printf("%d\n",j);
			if (i%ss[j]==0)
			{
				if (mn[i]==i)
				{
					mn[k]=k;
					d[k]=((d[i]*(ss[j]-1)+1)*ss[j]-1)/(ss[j]-1);
				}
				else mn[k]=mn[i]*ss[j],d[k]=d[i/mn[i]]*d[mn[i]*ss[j]];
				break;
			}
			d[k]=d[i]*d[ss[j]];
			mn[k]=ss[j];
		}
	}
	for (i=1;i<=n;i++) if (d[i]<=n&&!ys[d[i]]) ys[d[i]]=i;
	T=1;read(T);
	while (T--)
	{
		read(m);
		printf("%d\n",ys[m]?ys[m]:-1);
	}
}