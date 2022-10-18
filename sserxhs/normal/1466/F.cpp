#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
const int N=1e6+2,p=1e9+7;
int f[N],st[N],ed[N];
int n,c,i,t,m,j,k,tp,x,y,ans,z,w,la,s;
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
int getf(int x) {return f[x]==x?x:f[x]=getf(f[x]);}
int main()
{
	read(m);read(n);
	for (i=1;i<=n;i++) f[i]=i;
	for (i=1;i<=m;i++)
	{
		read(z);
		if (z==1) {read(x);x=getf(x);if (!ed[x]) ed[x]=1,st[++tp]=i;continue;}
		read(x);read(y);
		x=getf(x);y=getf(y);
		if (x==y||ed[x]&&ed[y]) continue;
		st[++tp]=i;f[x]=y;ed[y]|=ed[x];
	}
	printf("%d %d\n",ksm(2,tp),tp);
	for (i=1;i<=tp;i++) printf("%d%c",st[i],i==tp?10:32);
}