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
const int N=2e7+2,M=1e6+2,p=998244353;
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
		if (y&1) r*=x;
		x*=x;
		y>>=1;
	}
	return r;
}
ll ans,na;
int mn[N],ss[N>>2],ft[100],cs[100],ys[10000];
int T,n,m,c,d,i,j,gs,k,x,y,z,cnt,ct,xx;
void dfs(int x,int y)
{
	if (x>cnt) return ys[++ct]=y,void();
	for (int i=0;i<=cs[x];i++) {dfs(x+1,y);if (i==cs[x]) break;y*=ft[x];}
}
int main()
{
	n=2e7;
	for (i=2;i<=n;i++)
	{
		if (!mn[i]) ss[++gs]=i,mn[i]=i;
		for (j=1;j<=gs&&i*ss[j]<=n;j++)
		{
			mn[i*ss[j]]=ss[j];
			if (i%ss[j]==0) break;
		}
	}
	T=1;read(T);
	while (T--)
	{
		read(c);read(d);read(xx);
		y=__gcd(c,d);while (!y);
		if (xx%y) {puts("0");continue;}
		xx/=y;c/=y;d/=y;cnt=0;x=xx;
		while (x>1)
		{
			y=mn[x];ft[++cnt]=y;cs[cnt]=1;while (!y);
			x/=y;while (x%y==0) x/=y,++cs[cnt];
		}
		ct=0;
		dfs(1,1);ans=0;
		for (i=1;i<=ct;i++)
		{
			ll ls=(ll)ys[i]*d+xx;
			//printf("%d %lld\n",ys[i],ls);
			if (ls%c) continue;
			ls/=c;while(!c);
			if (ls%ys[i]) continue;na=1;
			//printf("%d %lldfas\n",ys[i],ls);
			ls/=ys[i];while(!ys[i]);
			x=ls;
			while (x>1)
			{
				y=mn[x];//if(!y)return 0;
				x/=y;while (x%y==0) x/=y,++cs[cnt];
				na<<=1;
			}
			ans+=na;
		}
		printf("%lld\n",ans);
	}
}