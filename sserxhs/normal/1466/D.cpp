#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
const int N=1e6+2;
struct Q
{
	int w,rd;
	bool operator<(const Q &o) const {return w>o.w;}
};
Q q[N];
ll ans;
int n,c,i,t,m,x,y,j,k,la,s,p;
inline void read(register int &x)
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
int main()
{
	read(t);
	while (t--)
	{
		read(n);
		ans=0;
		for (i=1;i<=n;i++) read(q[i].w),q[i].rd=-1,ans+=q[i].w;
		for (i=1;i<n;i++) read(x),read(y),++q[x].rd,++q[y].rd;
		sort(q+1,q+n+1);i=1;printf("%lld",ans);
		while (i<=n)
		{
			if (q[i].rd) --q[i].rd,ans+=q[i].w,printf(" %lld",ans); else ++i;
		}puts("");
	}
}