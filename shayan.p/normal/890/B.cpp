#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll sum;
int main()
{
	ll n,ans;cin>>n;ll a[n+10];
	set<ll>s;
	for(ll i=0;i<n;i++)cin>>a[i];
	for(ll i=n-1;i>=0;i--)
	{
		if(!s.count(a[i]))ans=a[i];
		s.insert(a[i]);
	}
	cout<<ans;
}