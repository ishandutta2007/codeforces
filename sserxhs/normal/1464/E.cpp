#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+2,M=520,p=998244353;
int dl[N],lj[N],nxt[N],rd[N],fir[N],a[M][M],f[N];
int n,c,i,t,m,j,k,tou,wei,mx,bs,x,y;
bool ed[N];
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
void add()
{
	lj[++bs]=y;
	nxt[bs]=fir[x];
	fir[x]=bs;
}
int main()
{
	read(n);read(m);
	while (m--)
	{
		read(x);read(y);++rd[y];add();
	}
	for (i=1;i<=n;i++) if (!rd[i]) dl[++wei]=i;
	while (tou<=wei) for (i=fir[x=dl[tou++]];i;i=nxt[i]) if (--rd[lj[i]]==0) dl[++wei]=lj[i];
	mx=7;
	for (i=n;i;i--)
	{
		x=dl[i];
		for (j=fir[x];j;j=nxt[j]) ed[f[lj[j]]]=1;
		for (j=0;;j++) if (!ed[j]) {f[x]=j;break;}mx=max(mx,f[x]);
		for (j=fir[x];j;j=nxt[j]) ed[f[lj[j]]]=0;
	}//return 0;
	while (mx!=(mx&-mx)) mx^=mx&-mx;mx=(mx<<1)-1;m=mx;
	for (i=0;i<=m;i++)
	{
		a[i][i]=p-(n+1);a[i][m+1]=(i!=0);
		for (j=1;j<=n;j++) ++a[i][i^f[j]];
	}
	//for (i=0;i<=m;i++)
	//{
	//	for (j=0;j<=m+1;j++) printf("%d ",a[i][j]);puts("");
//	}
	for (i=0;i<=m;i++)
	{
		for (j=i;j<=m;j++) if (a[j][i]) break;
		if (j!=i) swap(a[i],a[j]);
		x=ksm(a[i][i],p-2);
		for (j=i;j<=m+1;j++) a[i][j]=(ll)a[i][j]*x%p;
		for (j=0;j<=m;j++) if (j!=i)
		{
			x=a[j][i];
			if (x) for (k=i;k<=m+1;k++) a[j][k]=(a[j][k]+(ll)(p-x)*a[i][k])%p;
		}
	/*for (k=0;k<=m;k++)
	{
		for (j=0;j<=m+1;j++) printf("%d ",a[k][j]);puts("");
	}puts("");*/
	}
	//for (i=0;i<=m;i++) printf("%d\n",(p-a[i][m+1])%p);
	printf("%d",(p-a[0][m+1])%p);
}