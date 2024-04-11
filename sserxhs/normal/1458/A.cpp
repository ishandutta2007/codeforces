#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+2;
ll a[N],b[N],g;
int n,m,c,fh,i,t;
inline void read(int &x)
{
	c=getchar();fh=1;
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
inline void read(ll &x)
{
	c=getchar();fh=1;
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
	read(n);read(m);
	for (i=1;i<=n;i++) read(a[i]);
	for (i=1;i<=m;i++) read(b[i]);
	if (n==1)
	{
		for (i=1;i<=m;i++) printf("%lld ",a[1]+b[i]);return 0;
	}
	for (i=n;i;i--) a[i]-=a[i-1];
	g=a[n];
	for (i=2;i<n;i++) g=__gcd(g,a[i]);if (g<0) g=-g;
	for (i=1;i<=m;i++) printf("%lld ",__gcd(a[1]+b[i],g));
}