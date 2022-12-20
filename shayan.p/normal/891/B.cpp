#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
int main()
{
	ll n;cin>>n;
	pll a[n+10];
	ll ans[n+10];
	for(ll i=0;i<n;i++){ll x;cin>>x;a[i]=MP(x,i);}
	sort(a,a+n);
	for(ll i=0;i<n;i++)
		ans[a[i].S]=a[(i-1+n)%n].F;
	for(ll i=0;i<n;i++)cout<<ans[i]<<" ";
}