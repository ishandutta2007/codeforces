#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10,M=N*N;
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
template<typename typC, typename... Args> void read(typC &first, Args& ... args) {
	read(first);
	read(args...);
}
template<typename typC> void read(register typC *a,int num)
{
	for (register int i=1;i<=num;i++) read(a[i]);
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
template<typename typC> typC ab(register typC x)
{
	if (x<0) return -x;
	return x;
}
set<ll> p;
set<int> s;
int f[M],rk[M],st[M][2];
int nn,tp,ntp,L;
void init(int nnn)
{
	nn=nnn;
	for (int i=1;i<=nn;i++) f[i]=i,rk[i]=1;
	tp=0;
}
int getf(register int x)
{
	while (f[x]!=x) x=f[x];
	return x;
}
int getfa(int x)
{
	if (f[x]==x) return x;
	return f[x]=getfa(f[x]);
}
void uni(int x,int y)
{
	x=getf(x);y=getf(y);
	s.insert(x);
	if (x==y) return;
	s.insert(y);
	if (rk[x]>rk[y]) swap(x,y);
	st[++tp][0]=x;st[tp][1]=rk[y];
	if (rk[x]==rk[y]) ++rk[y];
	f[x]=y;
}
void fix()
{
	ntp=tp;
}
void roll()
{
	while (tp>ntp) rk[f[st[tp][0]]]=st[tp][1],f[st[tp][0]]=st[tp][0],--tp;
}
int dir[9][2]={{0,0},{1,0},{0,1},{1,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
int id[N][N],a[N][N],b[N][2];
int n,m,q,i,j,k,cnt,c,l,x,y,z;
inline bool av(int x,int y)
{
	return x>=0&&x<=n&&y>=0&&y<=m; 
}
int main()
{
	read(n,m,q);
	for (i=1;i<=n;i++)
	{
		c=getchar();
		while (c!='.'&&c!='#') c=getchar();
		a[i][1]=c=='#';
		for (j=2;j<=m;j++) a[i][j]=getchar()=='#';
	}
	++n;++m;
	for (i=3;i<=n;i++) a[i][0]=1;
	for (i=1;i+2<m;i++) a[n][i]=1;
	for (i=3;i<=m;i++) a[0][i]=1;
	for (i=0;i+2<n;i++) a[i][m]=1;
	for (i=0;i<=n;i++) for (j=0;j<=m;j++) id[i][j]=++cnt;
	init(cnt);
	for (i=0;i<=n;i++) for (j=0;j<=m;j++) if (a[i][j])
	{
		for (k=1;k<=8;k++) if (av(x=i+dir[k][0],y=j+dir[k][1])&&a[x][y]) f[getfa(id[i][j])]=getfa(id[x][y]);
	}
	for (i=1;i<=cnt;i++) getfa(i);
	for (i=0;i<=n;i++) for (j=0;j<=m;j++) if (a[i][j]) for (k=-2;k<=2;k++) for (l=-2;l<=2;l++) if (av(x=i+k,y=j+l)&&a[x][y])
	{
		z=getfa(id[i][j]);c=getfa(id[x][y]);
		if (z==c) continue;
		p.insert((ll)z*cnt+c);
	}
	for (i=1;i<=cnt;i++) if (f[i]!=i) rk[f[i]]=2;
	fix();
	for (int ii=1;ii<=q;ii++)
	{
		roll();
		read(L);
		s.erase(s.begin(),s.end());
		s.insert(getf(id[n][0]));s.insert(getf(id[0][m]));
		for (i=1;i<=L;i++)
		{
			read(b[i]-1,2);a[b[i][0]][b[i][1]]=1;
		}
		if (a[1][1]||a[n-1][m-1])
		{
			puts("NO");
			goto aaa;
		}
		for (i=1;i<=L;i++)
		{
			for (k=1;k<=8;k++) if (av(x=b[i][0]+dir[k][0],y=b[i][1]+dir[k][1])&&a[x][y]) uni(id[b[i][0]][b[i][1]],id[x][y]);
		}
		if (getf(id[n][0])==getf(id[0][m]))
		{
			puts("NO");
			goto aaa;
		}
		for (auto u:s) if (getf(u)==getf(id[n][0])) for (auto v:s) if (getf(v)==getf(id[0][m])&&p.find((ll)u*cnt+v)!=p.end())
		{
			puts("NO");
			goto aaa;
		}
		for (i=1;i<=L;i++) if (getf(id[x=b[i][0]][y=b[i][1]])==getf(id[n][0])) for (k=-2;k<=2;k++) for (l=-2;l<=2;l++) if (av(z=x+k,c=y+l)&&a[z][c]&&getf(id[z][c])==getf(id[0][m]))
		{
			puts("NO");
			goto aaa;
		}
		for (i=1;i<=L;i++) if (getf(id[x=b[i][0]][y=b[i][1]])==getf(id[0][m])) for (k=-2;k<=2;k++) for (l=-2;l<=2;l++) if (av(z=x+k,c=y+l)&&a[z][c]&&getf(id[z][c])==getf(id[n][0]))
		{
			puts("NO");
			goto aaa;
		}
		puts("YES");
		aaa:;
		for (i=1;i<=L;i++) a[b[i][0]][b[i][1]]=0;
		fflush(stdout);
	}
}