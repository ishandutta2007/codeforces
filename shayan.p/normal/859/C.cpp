#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=60;
const ll inf=1e18;
ll dp[maxn][2],a[maxn];
int main()
{
	ll s=0,n;cin>>n;for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=n;i>=1;i--)
	{
		ll x;x=a[i];s+=x;
		dp[i][0]=s-max(dp[i+1][0],dp[i+1][1]);
		dp[i][1]=max(dp[i+1][1],dp[i+1][0]);
	}
	ll x=max(dp[1][0],dp[1][1]);
	cout<<s-x<<" "<<x;
}