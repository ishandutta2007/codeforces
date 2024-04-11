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
int t,n,k,a[200001];
void solve()
{
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
		a[i]=read()+a[i-1];
	if(k>=n)
	{
		cout<<a[n]+n*(2*k-1-n)/2<<'\n';
		return ;
	}
	int ans=0;
	for(int i=k;i<=n;i++)
		ans=max(ans,a[i]-a[i-k]);
	cout<<ans+k*(k-1)/2<<'\n';
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}