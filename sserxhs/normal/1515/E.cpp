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
const int N=401,M=1e6+2;
int p;
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
int f[2][N][N][2],g[N][N][N],hf[2][N][N][2],hg[N][N];
int T,n,m,c,i,j,k,l,x,y,z,ans,la;
int main()
{
	read(n);read(p);
	f[0][1][2][0]=1;f[0][2][2][1]=1;g[3][1][2]=1;g[3][2][2]=1;
	for (i=2;i<n;i++)
	{
		x=i&1;y=x^1;
		memset(hf[y],0,sizeof(hf[y]));
		memset(f[y],0,sizeof(f[y]));
		for (j=1;j<=i;j++) for (l=j;l<=i;l++)
		{
			inc(hf[y][j+1][l+1][1],f[x][j][l][1]);
			if (i<n-1) inc(hg[i+2][l+1],f[x][j][l][1]);
			inc(hf[y][1][l+1][0],f[x][j][l][0]);
			dec(hf[y][j+1][l+1][0],f[x][j][l][0]);
			inc(hf[y][1+j][l+1][1],f[x][j][l][0]);
			if (i<n-1) 	inc(hg[i+2][l+1],f[x][j][l][0]);
		}
		if (i<n-1) 	for (l=1;l<=i;l++) for (j=1;j<=l;j++) inc(hg[i+2][l+1],g[i][j][l]);
		for (l=1;l<=i;l++) for (k=1;k<=l;k++)
		{
			inc(hf[y][1][l+1][0],g[i][k][l]);
			dec(hf[y][k+1][l+1][0],g[i][k][l]);
			inc(hf[y][k+1][l+1][1],g[i][k][l]);
		}
		for (k=1;k<=i+1;k++) for (l=k;l<=i+1;l++) for (j=0;j<=1;j++) 
		{
			inc(hf[y][k][l][j],hf[y][k-1][l][j]),inc(f[y][k][l][j],hf[y][k][l][j]);
		}
		if (i<n-1) 	for (l=1;l<=i+2;l++) for (k=1;k<=l;k++)
		{
			inc(g[i+2][k][l],hg[i+2][l]);
		}
	}
	for (i=1;i<=n;i++) for (l=i;l<=n;l++)for (j=0;j<=1;j++)  inc(ans,f[n&1][i][l][j]);
	for (l=1;l<=n;l++) for (i=1;i<=l;i++) inc(ans,g[n][i][l]);
	
	//for (i=1;i<=n;i++) assert(f[n][i][i]==0);
	write(ans);
}