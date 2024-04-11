#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
const int N=3e5+2,M=1.2e6+2;
int bel[N],a[N],l[M],r[M],ys[N],pre[N],s[M],ans[N],b[N];
int n,m,c,fh,i,x,j,y;
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
void build(int x)
{
	if (l[x]==r[x]) {ys[l[x]]=x;return;}
	l[c=x<<1]=l[x];r[c]=l[x]+r[x]>>1;
	l[c|1]=r[c]+1;r[c|1]=r[x];
	build(c);build(x<<1|1);
}
inline void add(register int x)
{
	for (register int i=x;i;i^=(i&(-i))) ++b[i]; 
}
inline int sum(register int x)
{
	register int r=0;
	for (register int i=x;i<=n;i+=(i&(-i))) r+=b[i];
	return r;
}
struct Q
{
	int z,y,wz;
	bool operator<(const Q& x) const {return y<x.y;}
};
Q q[N];
int main()
{
	//freopen("a.in","r",stdin);
	read(n);read(m);
	for (i=1;i<=n;i++) {read(a[i]);if (a[i]<=i) a[i]=i-a[i]; else a[i]=n+1;}
	r[l[1]=1]=n;build(1);
	for (i=1;i<=n;i++) if (a[i]<=s[1])
	{
		x=1;c=a[i];
		while (l[x]!=r[x]) if (s[y=x<<1|1]>=c) x=y; else {c-=s[y];x<<=1;}
		if (l[x]>i) x=ys[i];
		pre[i]=l[x];++s[x];
		while (x=x>>1) ++s[x];
	}
	//for (i=1;i<=n;i++) printf("%d ",a[i]);puts("");
	//for (i=1;i<=n;i++) printf("%d ",pre[i]);puts("");
	for (i=1;i<=m;i++) {read(q[i].z);read(q[q[i].wz=i].y);++q[i].z;q[i].y=n-q[i].y;}
	sort(q+1,q+m+1);
	for (i=j=1;i<=m;i++)
	{
		while (j<=q[i].y) 
		{
			if (pre[j]) add(pre[j]);
			++j;
		}
		ans[q[i].wz]=sum(q[i].z);
	}
	for (i=1;i<=m;i++) printf("%d\n",ans[i]);
}