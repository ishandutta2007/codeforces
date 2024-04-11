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
int t,n,ans,a[100001];
unordered_map<int,int> mp1,mp2;
const int mod=998244353;
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	ans=0;
	mp2.clear();
	for(int i=n;i;i--)
	{
		swap(mp1,mp2);
		mp2.clear();
		for(auto l:mp1)
		{
			int k=(a[i]-1)/l.first;
			(ans+=k*l.second%mod*i%mod)%=mod;
			int rest=a[i]/(k+1);
			(mp2[rest]+=l.second)%mod;
		}
		mp2[a[i]]++;
	}
	cout<<ans<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}