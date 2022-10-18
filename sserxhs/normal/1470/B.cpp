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
map<vector<int>,int> mp;
map<vector<int>,int>::iterator it,jt;
vector<int> a[N];
char s[N];
int b[N],ss[M],mn[M],fs[M];
int T,n,m,c,i,j,k,gs,x,y,z,ans,la,tot;
int main()
{
	n=1e6;
	for (i=2;i<=n;i++)
	{
		if (!mn[i]) ss[++gs]=mn[i]=i,fs[i]=gs;
		for (j=1;j<=gs&&ss[j]*i<=n;j++)
		{
			mn[i*ss[j]]=ss[j];
			if (i%ss[j]==0) break;
		}
	}
	read(T);
	while (T--)
	{
		read(n);mp.clear();tot=0;
		for (i=1;i<=n;i++)
		{
			a[i].clear();
			read(x);
			while (x>1)
			{
				y=mn[x];z=1;x/=y;
				while (mn[x]==y) x/=y,z^=1;
				if (z) a[i].push_back(fs[y]);
			}
			if (a[i].size()) ++mp[a[i]]; else ++tot;
		}ans=la=tot;
		for (it=mp.begin();it!=mp.end();it++)
		{
			ans=max(ans,it->second);
			if (1^it->second&1) la=max(la,tot+=it->second);
		}la=max(la,ans);
		read(m);
		while (m--)
		{
			ll x;
			read(x);
			printf("%d\n",x?la:ans);
		}
	}
}