#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool cmp(ll a,ll b){return a>b;}
multiset<ll> st;
int main()
{
	ll n;cin>>n;ll a[n+10];for(ll i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,greater<ll>());
	for(ll i=1;i<=n;i++)//ta jabe i bozorgoo
	{
		bool yes;yes=1;
		st.clear();
		for(ll j=0;j<i;j++)	st.insert(-a[j]);
		for(ll j=i;j<n;j++)
		{
			ll x=*(st.begin());
			if(x==0){yes=0;break;}
			x=max(x+1,-a[j]);
			st.erase(st.begin());st.insert(x);
		}
		if(yes){cout<<i;return 0;}
	}
}