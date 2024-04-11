#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int t,n,k,ans,b[1001],c[1001],f[1000001],g[1001];
void mx(int &x,int y)
{
	if(x<y)
		x=y;
}
void mn(int &x,int y)
{
	if(x>y)
		x=y;
}
void solve()
{
	n=read();
	k=min(read(),13*n);
	for(int i=0;i<=k;i++)
		f[i]=0;
	for(int i=1;i<=n;i++)
		b[i]=g[read()];
	for(int i=1;i<=n;i++)
		c[i]=read();
	for(int i=1;i<=n;i++)
		for(int l=k;l>=b[i];l--)
			mx(f[l],f[l-b[i]]+c[i]);
	ans=0;
	for(int i=0;i<=k;i++)
		ans=max(ans,f[i]);
	cout<<ans<<'\n';
}
signed main()
{
	for(int i=2;i<=1000;i++)
		g[i]=INF;
	for(int i=1;i<=1000;i++)
		for(int l=1;l<=i;l++)
			mn(g[i+i/l],g[i]+1);
	t=read();
	while(t--)
		solve();
	return 0;
}