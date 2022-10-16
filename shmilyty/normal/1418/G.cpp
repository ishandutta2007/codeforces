#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
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
int n,ans,a[500001],hsh[500001],cnt[500001],val[500001],pre[500001],lst[500001];
map<int,int> mp;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		hsh[i]=rng();
	mp[0]=1;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		cnt[a[i]]++;
		cnt[a[i]]%=3;
		if(cnt[a[i]])
			val[i]=val[i-1]+hsh[a[i]];
		else
			val[i]=val[i-1]-2*hsh[a[i]];
	}
	for(int i=1;i<=n;i++)
	{
		pre[i]=lst[a[i]];
		lst[a[i]]=i;
	}
	int now=-1;
	for(int i=1;i<=n;i++)
	{
		int pos=pre[pre[pre[i]]]-1;
		while(now<pos)
			mp[val[++now]]--;
		ans+=mp[val[i]];
		mp[val[i]]++;
	}
	cout<<ans;
	return 0;
}