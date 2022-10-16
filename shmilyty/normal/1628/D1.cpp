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
const int mod=1e9+7;
int t,n,m,k,f[2001][2002];
void solve()
{
	n=read();
	m=read();
	k=read();
	for(int i=0;i<=n;i++)
		for(int l=0;l<=n;l++)
			f[i][l]=0;
	for(int i=0;i<=n;i++)
		for(int l=0;l<=m;l++)
			if(i+(m-l)==n)
				f[i][l]=k*(m-l)%mod;
	for(int i=n-1;i>=0;i--)
		for(int l=m;l>=0&&i+(m-l)<n;l--)
			f[i][l]=(f[i+1][l]+f[i+1][l+1])*((mod+1)/2)%mod;
	cout<<f[0][0]<<'\n';
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}