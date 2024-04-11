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
const int N=1.5e3+20,p=383778817;
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
typedef pair<ull,int> pa;
ull hs;
bitset<N> nx[N],bs;
int a[N][N],b[N][N],r[N][N],st[N];
int T,n,m,c,i,j,k,x,y,z,ans,la,cnt,hh,tp;
map<pa,int> mp;
vector<int> s[N];
bool vis[N];
int main()
{
	read(n);read(m);++m;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<m;j++) read(a[i][j]);a[i][m]=i;hs=hh=0;
		for (j=1;j<m;j++) hs=hs*2357ull+a[i][j],hh=(hh*2357ll+a[i][j])%p;
		if (mp.find(pa(hs,hh))!=mp.end())
		{
			s[mp[pa(hs,hh)]].push_back(i);
		} else s[mp[pa(hs,hh)]=++cnt].push_back(i);
	}//printf("%d %d\n",cnt,s[1][0]);
	for (i=1;i<=cnt;i++) reverse(s[i].begin(),s[i].end());
	for (i=1;i<=n;i++)
	{
		for (j=1;j<m;j++) read(b[i][j]);hs=hh=0;
		for (j=1;j<m;j++) hs=hs*2357ull+b[i][j],hh=(hh*2357ll+b[i][j])%p;
		if (mp.find(pa(hs,hh))==mp.end())
		{
			puts("-1");return 0;
		}
		la=mp[pa(hs,hh)];//printf("la=%d\n",la);
		if (!s[la].size()) return puts("-1"),0;
		b[i][m]=s[la][s[la].size()-1];
		s[la].pop_back();
	}
	//printf("%d %d\n",b[1][m],b[2][m]);
	for (j=1;j<=m;j++) for (i=n-1;i;i--) if (b[i][j]>b[i+1][j]) nx[j][i]=1;
	//bs.set();assert(!bs[0]);
	for (i=1;i<n;i++) bs[i]=1;
	for (i=1;i<=m;i++)
	{
		for (j=1;j<=m;j++) if (!vis[j]&&(bs&nx[j]).count()==0)
		{
			st[++tp]=j;vis[j]=1;break;
		}
		if (j>m) return puts("-1"),0;
		if (j==m) {--tp;break;}
		for (k=1;k<n;k++) if (bs[k]&&b[k][j]<b[k+1][j]) bs[k]=0;
		//printf("%d\n",bs.count());
		if (bs.count()==0) break;
	}
	printf("%d\n",tp);
	while (tp) printf("%d ",st[tp--]);
}