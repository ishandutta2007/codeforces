#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
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
	register int tp=1,y;st[1]=x%10;x/=10;
	while (x) y=x/10,st[++tp]=x-y*10,x=y;++tp;
	while (--tp) putchar(st[tp]|48);
}
template<typename typC> void write(register typC *a,register int num)
{
	for (register int i=1;i<=num;i++) write(a[i]),putchar(i==num?10:32);
}
#define space(x) write(x),putchar(32)
#define enter(x) write(x),putchar(10)
const int N=1e6+2,M=1e6+2,p=998244353;
inline void inc(register int &x,const int y)
{
	if ((x+=y)>=p) x-=p;
}
inline void dec(register int &x,const int y)
{
	if ((x-=y)<0) x+=p;
}
priority_queue<int,vector<int>,greater<int> > heap;
char s[N];
int a[N],b[N];
ll ans;
int T,n,m,c,i,j,k,x,y,z,la;
int main()
{
	read(T);
	while (T--)
	{
		ans=0;while (!heap.empty()) heap.pop();
		read(n);read(m);
		for (i=1;i<=n;i++) read(a[i]);
		for (i=1;i<=m;i++) read(b[i]);
		sort(a+1,a+n+1);
		j=1;
		for (i=1;i<=n;i++)
		{
			while (j<=a[i]) heap.push(b[j++]);
			if (heap.top()<b[a[i]]) ans+=heap.top(),heap.pop(),heap.push(b[a[i]]); else ans+=b[a[i]];
			//printf("%d %lld\n",a[i],ans);
		}
		printf("%lld\n",ans);
	}
}