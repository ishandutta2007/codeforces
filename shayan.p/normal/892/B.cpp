#include<bits/stdc++.h>
#define ll int
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
const ll maxn=1e6;
ll l[maxn];
int main()
{
	ll n;cin>>n;
	ll last=n,beg=n-1;
	for(ll i=0;i<n;i++)cin>>l[i];
	ll ans=0;
	for(ll i=n-1;i>=0;i--)
	{
		if(i<last)
		{
		ans+=beg-last;
		beg=i;
		}
		last=max(min(i-l[i],last),(ll)0);
	}
	if(last==0){ans+=beg-last+1;}
	cout<<n-ans;	
}