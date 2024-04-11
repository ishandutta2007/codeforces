#include<bits/stdc++.h>//1
#define int long long
using namespace std;
int n,ans,a[200001],l[200001];
vector<int> v[200001];
void dfs(int x)
{
	if(v[x].size()==0)
	{
		l[x]=1;
		return ;
	}
	for(int i=0;i<v[x].size();i++)
	{
		dfs(v[x][i]);
		a[x]+=a[v[x][i]];
		l[x]+=l[v[x][i]];
	}
}
signed main()
{
	scanf("%lld",&n);
	for(int i=2;i<=n;i++)
	{
		int p;
		scanf("%lld",&p);
		v[p].push_back(i);
	}
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	dfs(1);
	for(int i=1;i<=n;i++)
		ans=max(ans,(a[i]+l[i]-1)/l[i]);
	cout<<ans;
	return 0;
}