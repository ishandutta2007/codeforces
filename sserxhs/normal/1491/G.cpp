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
	register int tp=1,y;st[1]=x%10;x/=10;
	while (x) y=x/10,st[++tp]=x-y*10,x=y;++tp;
	while (--tp) putchar(st[tp]|48);
}
template<typename typC> void write(register typC *a,register int num)
{
	for (register int i=1;i<=num;i++) write(a[i]),putchar(i==num?10:32);
}
#define space(x) write(x),putchar(32)
#define enter(x) write(x),putchar(10)
const int N=1e6+2,M=1e6+2,p=998244353;
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
vector<int> bel[N];
char s[N];
int a[N],ed[N],st[N],ans[N][2];
int T,n,m,c,i,j,k,x,y,z,ass,la,tp;
int main()
{
	read(n);
	for (i=1;i<=n;i++) read(a[i]);
	for (i=1;i<=n;i++) if (!ed[i])
	{
		ed[i]=i;bel[i].push_back(i);
		for (j=a[i];j!=i;j=a[j]) ed[j]=i,bel[i].push_back(j);
	}
	for (i=1;i<=n;i++) if (ed[i]==i) st[++tp]=i;
	for (i=1;i+1<=tp;i+=2)
	{
		x=st[i];y=st[i+1];
		ans[++ass][0]=bel[x][0];ans[ass][1]=bel[y][0];
		for (int i=1;i<bel[x].size();i++) ans[++ass][0]=bel[y][0],ans[ass][1]=bel[x][i];
		for (int i=1;i<bel[y].size();i++) ans[++ass][0]=bel[x][0],ans[ass][1]=bel[y][i];
		ans[++ass][0]=bel[x][0];ans[ass][1]=bel[y][0];
	}
	for (;tp&1;)
	{
		if (bel[st[tp]].size()==1) break;x=st[tp];
		if (bel[x].size()==2)
		{
			for (i=1;i<=n;i++) if (i!=bel[x][0]&&i!=bel[x][1]) break;
			ans[++ass][0]=bel[x][0],ans[ass][1]=i;
			ans[++ass][0]=bel[x][1],ans[ass][1]=i;
			ans[++ass][0]=bel[x][0],ans[ass][1]=i;break;
		}
		for (i=1;i+1<bel[x].size();i++) ans[++ass][0]=bel[x][0],ans[ass][1]=bel[x][i];
		ans[++ass][0]=bel[x][1];ans[ass][1]=bel[x][bel[x].size()-1];
		ans[++ass][0]=bel[x][0];ans[ass][1]=bel[x][bel[x].size()-1];
		ans[++ass][0]=bel[x][1];ans[ass][1]=bel[x][0];
		break;
	}
	printf("%d\n",ass);
	for (i=1;i<=ass;i++) printf("%d %d\n",ans[i][0],ans[i][1]);
}