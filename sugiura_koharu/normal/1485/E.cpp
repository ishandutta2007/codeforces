#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
using namespace std;
vector <int> e[200005];
int dep[200005],fa[200005],w1[200005],w2[200005],dp[200005],a[200005];
inline void dfs(int u,int f)
{
	fa[u]=f;
	for(auto v:e[u])
		dep[v]=dep[u]+1,dfs(v,u);
}
vector <int> s[200005];
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) e[i].clear(),s[i].clear();
		for(int i=2;i<=n;i++)
		{
			int x;
			scanf("%lld",&x);
			e[x].push_back(i);
		}
		dfs(1,0);
		for(int i=2;i<=n;i++)
			scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++)
			s[dep[i]].push_back(i);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(auto x:s[i])dp[x]=max(w2[fa[x]],w1[fa[x]]);
			int mx=-1e18,mn=1e18;
			for(auto x:s[i]) mn=min(mn,a[x]),mx=max(mx,a[x]);
			for(auto x:s[i]) w1[x]=dp[x]+max(a[x]-mn,mx-a[x]);
			mx=-1e18,mn=1e18;
			for(auto x:s[i]) mn=min(mn,a[x]-dp[x]),mx=max(mx,a[x]+dp[x]);
			for(auto x:s[i]) w2[x]=max(a[x]-mn,mx-a[x]);
		}
		for(int i=1;i<=n;i++)
		{
		//	cout << w1[i] << " " << dp[i] << "\n";
			ans=max(ans,w1[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}