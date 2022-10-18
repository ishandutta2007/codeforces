#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e2+2,M=1e5+2,inf=1e9;
int f[M],x[M],t[M],y[M],g[M];
int n,m,c,fh,i;
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
inline int ab(const int x)
{
	if (x>0) return x;return -x;
}
int main()
{
	read(m);read(n);
	register int i,j,k;
	for (i=1;i<=n;i++) {read(t[i]);read(x[i]);read(y[i]);f[i]=g[i]=-inf;}
	x[0]=y[0]=1;
	for (i=1;i<=n;i++)
	{
		for (j=i-1;(~j)&&(t[i]-t[j]<=1000);j--) if (t[i]-t[j]>=ab(x[i]-x[j])+ab(y[i]-y[j])) f[i]=max(f[i],f[j]+1);
		if (j>=0) f[i]=max(f[i],g[j]+1);g[i]=max(g[i-1],f[i]);
		//printf("%d %d\n",f[i],g[i]);
	}printf("%d",g[n]);
}