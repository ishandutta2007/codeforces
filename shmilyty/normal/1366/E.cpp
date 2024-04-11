#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,ans=1,minn,a[200001],b[200001];
map<int,int> cnt;
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%lld",&b[i]);
	minn=a[n];
	for(int i=n;i>=1;i--)
	{
		minn=min(minn,a[i]);
		cnt[minn]++;
	}
	if(minn!=b[1])
	{
		cout<<0;
		return 0;
	}
	for(int i=2;i<=m;i++)
		ans=ans*cnt[b[i]]%mod;
	cout<<ans;
	return 0;
}