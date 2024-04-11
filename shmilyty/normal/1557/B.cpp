#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
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
int t,n,k,ans,cnt,a[100001],vis[100001];
map<int,int> mp;
void solve()
{
	n=read();
	k=read();
	mp.clear();
	cnt=ans=0;
	for(int i=0;i<=n;i++)
		vis[i]=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		mp[a[i]];
	}
	for(auto &i:mp)
		i.second=++cnt;
	ans=1;
	for(int i=1;i<=n;i++)
	{
		a[i]=mp[a[i]];
		if(a[i]!=a[i-1]+1&&i!=1)
			ans++;
	}
	if(ans<=k)
		puts("Yes");
	else
		puts("No");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}