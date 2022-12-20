#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
ll sum[1000];
int main()
{
	ll n,ans=1000;cin>>n;
	ll a[n+10],sum[n+10];
	for(ll i=1;i<=n;i++){
	cin>>a[i];
	sum[i]=sum[i-1]+a[i];
	}
	for(ll i=1;i<=n;i++)
		for(ll j=i;j<=n;j++){
			ll num=(sum[j]-sum[i-1]);
			ans=min(ans,abs(num-(360-num)));
		}
	cout<<ans<<endl;
}