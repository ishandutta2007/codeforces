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
template<typename typC> void read(typC &x)
{
	int c=getchar(),fh=1;
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
template<typename typC> void write(typC x)
{
	if (x<0) putchar('-'),x=-x;
	static int st[100];
	int tp=1;
	typC y;st[1]=x%10;x/=10;
	while (x) y=x/10,st[++tp]=x-y*10,x=y;++tp;
	while (--tp) putchar(st[tp]|48);
}
template<typename typC> void write(typC *a,int num)
{
	for (int i=1;i<=num;i++) write(a[i]),putchar(i==num?10:32);
}
inline int ab(int x){return x>0?x:-x;}
#define space(x) write(x),putchar(32)
#define enter(x) write(x),putchar(10)
const int N=502,M=1e6+2,p=998244353;
inline void inc(int &x,const int y)
{
	if ((x+=y)>=p) x-=p;
}
inline void dec(int &x,const int y)
{
	if ((x-=y)<0) x+=p;
}
inline int ksm(int x,int y)
{
	int r=1;
	while (y)
	{
		if (y&1) r=(ll)r*x%p;
		x=(ll)x*x%p;
		y>>=1;
	}
	return r;
}
typedef pair<int,int> pa;
priority_queue<pa,vector<pa>,greater<pa> > heap;
int a[N][N],b[N][N],ad[N][N],dis[10][N][N],ys[N][N],fs[N*N][2],anss[N][N];
int T,n,m,c,i,j,k,l,x,y,z,ans,la;
bool av[N][N],ed[N*N];
void ck(int z,int x,int y,int ds)
{
	//if (x<1||y<1||x>n||y>m) return;
	if (dis[z][x][y]>ds) dis[z][x][y]=ds;
}
int main()
{
	//n=500;m=500;c=20;
	read(n);read(m);read(c);


	int cc=c>>1;--cc;
	if (c&1)
	{
		for (i=1;i<=n;i++) for (j=1;j<=m;j++) printf("-1%c",j==m?10:32);
		return 0;
	}
	memset(ad,0x3f,sizeof(ad));
	//for (i=1;i<=n;i++) for (j=1;j<m;j++) a[i][j]=i+j;//
	//for (i=1;i<n;i++) for (j=1;j<=m;j++) b[i][j]=i^j;//
	for (i=1;i<=n;i++) for (j=1;j<m;j++) read(a[i][j]);//
	for (i=1;i<n;i++) for (j=1;j<=m;j++) read(b[i][j]);//
	for (i=1;i<=n;i++) for (j=1;j<=m;j++)
	{
		if (i!=1) ad[i][j]=min(ad[i][j],b[i-1][j]);
		if (j!=1) ad[i][j]=min(ad[i][j],a[i][j-1]);
		if (i!=n) ad[i][j]=min(ad[i][j],b[i][j]);
		if (j!=m) ad[i][j]=min(ad[i][j],a[i][j]);
		assert(ad[i][j]!=ad[0][0]);
	}
	//for (i=1;i<=n;i++) for (j=1;j<=m;j++) printf("%d%c",ad[i][j],j==m?10:32);
	//for (i=1;i<=n;i++) for (j=1;j<=m;j++) ys[i][j]=++ans,fs[ans][0]=i,fs[ans][1]=j;
	memset(anss,0x3f,sizeof(anss));
	for (i=1;i<=n;i++) for (j=1;j<=m;j++)
	{
		for (k=-cc;k<=cc;k++) if (i+k>=1&&i+k<=n) for (la=ab(k),l=-cc+la;l<=cc-la;l++) if (j+l>=1&&j+l<=m)
		{
			//av[i+k][j+l]=1;ed[ys[i+k][j+l]]=0;
			for (int ii=0;ii<=cc;ii++) dis[ii][i+k][j+l]=p;
		}
		dis[0][i][j]=0;//while (!heap.empty()) heap.pop();
		for (int ii=0;ii<cc;ii++)
		{
			for (k=-ii;k<=ii;k++) if (i+k>=1&&i+k<=n) for (la=ab(k),l=-ii+la;l<=ii-la;l++) if (j+l>=1&&j+l<=m)
			{
				//if (i==1&&j==1) printf("%d %d %d %d\n",ii,i+k,j+l,dis[ii][i+k][j+l]);
				int nx=i+k,ny=j+l;
				if (nx>1) ck(ii+1,nx-1,ny,dis[ii][nx][ny]+b[nx-1][ny]);
				if (ny>1) ck(ii+1,nx,ny-1,dis[ii][nx][ny]+a[nx][ny-1]);
				if (nx<n) ck(ii+1,nx+1,ny,dis[ii][nx][ny]+b[nx][ny]);
				if (ny<m) ck(ii+1,nx,ny+1,dis[ii][nx][ny]+a[nx][ny]);
			}
		}
		for (int ii=0;ii<=cc;ii++)
		{
			for (k=-ii;k<=ii;k++) if (i+k>=1&&i+k<=n) for (la=ab(k),l=-ii+la;l<=ii-la;l++) if (j+l>=1&&j+l<=m)// if (i>l&&j+l<=m)
			{
				anss[i][j]=min(anss[i][j],dis[ii][i+k][j+l]*2+ad[i+k][j+l]*(c-ii*2));
			}
		}
		//for (k=-9;k<=9;k++) if (i>k&&i+k<=n) for (la=ab(k),l=-9+la;l<=9-la;l++) if (i>l&&j+l<=m) anss[i][j]=min(anss[i][j],dis[i+k][j+l]*2+);
		//for (k=-9;k<=9;k++) if (i>k&&i+k<=n) for (la=ab(k),l=-9+la;l<=9-la;l++) if (i>l&&j+l<=m) av[i+k][j+l]=0;
	}
	for (i=1;i<=n;i++) for (j=1;j<=m;j++) printf("%d%c",anss[i][j],j==m?10:32);
}