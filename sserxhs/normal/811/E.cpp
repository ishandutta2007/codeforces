#include <bits/stdc++.h>
using namespace std;
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e5+5;
template<typename typC> struct bit
{
	vector<typC> _a,_s;
	typC *a,*s;
	int n;
	bit(){}
	bit(int nn)
	{
		n=nn++;
		_a.resize(nn);a=_a.data();
		_s.resize(nn);s=_s.data();
	}
	template<typename T> void init(int nn,T *b)
	{
		n=nn++;
		_a.resize(nn);a=_a.data();
		_s.resize(nn);s=_s.data();
		for (int i=1;i<=n;i++) s[i]=s[i-1]+b[i];
	}
	void mdf(int x,typC y)
	{
		a[x]+=y;
		while ((x+=x&-x)<=n) a[x]+=y; 
	}
	typC sum(int x)
	{
		typC r=s[x]+a[x];
		while (x^=x&-x) r+=a[x];
		return r;
	}
	typC sum(int x,int y)
	{
		return sum(y)-sum(x-1);
	}
};
struct Q
{
	int l,r,p;
};
int a[12][N],V[N],E[2][N],ans[N],f[11*N],l[11*N],r[11*N],sz[11*N];
int getf(int u) {return f[u]==u?u:f[u]=getf(f[u]);}
void uni(int u,int v) {f[getf(u)]=getf(v);}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m,q,i,j;
	cin>>n>>m>>q;
	for (i=1;i<=n;i++) for (j=1;j<=m;j++) cin>>a[i][j];
	for (i=1;i<n;i++) for (j=1;j<m;j++) V[j]+=a[i][j]!=a[i+1][j]||a[i][j]!=a[i+1][j+1]||a[i][j]!=a[i][j+1];
	for (i=1;i<=n;i++) for (j=1;j<m;j++) E[1][j]+=a[i][j]!=a[i][j+1];
	for (i=1;i<n;i++) for (j=1;j<=m;j++) E[0][j]+=a[i][j]!=a[i+1][j];
	//for (i=1;i<=m;i++) dbgn(i,V[i],E[0][i],E[1][i]);
	for (i=1;i<=m;i++) E[0][i]+=E[0][i-1],E[1][i]+=E[1][i-1],V[i]+=V[i-1];
	vector<Q> b(q);
	for (i=1;i<=q;i++)
	{
		auto &[l,r,p]=b[i-1];
		cin>>l>>r;p=i;
		ans[i]=(E[0][r]-E[0][l-1])+(E[1][r-1]-E[1][l-1])+1-(V[r-1]-V[l-1]);
	}
	iota(f,f+(n+1)*(m+1),0);
	for (i=0;i<=n;i++) for (j=0;j<=m;j++) l[i*(m+1)+j]=r[i*(m+1)+j]=j;
	for (i=0;i<=n;i++) for (j=1;j<=m;j++) if (a[i][j]!=a[i+1][j]) uni(i*(m+1)+j-1,i*(m+1)+j);
	for (i=1;i<=n;i++) for (j=0;j<=m;j++) if (a[i][j]!=a[i][j+1]) uni((i-1)*(m+1)+j,i*(m+1)+j);
	for (i=0;i<=n;i++) for (j=0;j<=m;j++)
	{
		int F=getf(i*(m+1)+j);
		l[F]=min(l[F],j);r[F]=max(r[F],j);
		++sz[F];
	}
	for (i=0;i<(n+1)*(m+1);i++) if (f[i]==i&&l[i]&&r[i]<m&&sz[i]>1) b.push_back({l[i],r[i],0});
	sort(all(b),[&](const Q &a,const Q &b) {return a.l==b.l?a.p<b.p:a.l>b.l;});
	bit<int> s(m);
	for (auto [l,r,p]:b) if (p) ans[p]+=s.sum(r-1); else s.mdf(r,1);
	for (i=1;i<=q;i++) cout<<ans[i]<<'\n';
}