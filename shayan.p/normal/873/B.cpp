#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define S second
#define F first
#define PB push_back
#define MP make_pair
using namespace std;
map<ll,ll> mp_f,mp_s;
int main()
{
	ll n;cin>>n;string s;cin>>s;ll sum=0;mp_f[0]=0;ll ans=0;
	for(ll i=1;i<n+1;i++)
	{
	sum+=(s[i-1]=='0')?(-1):1;
	if(mp_f.count(sum)) {mp_s[sum]=i;ans=max(ans,mp_s[sum]-mp_f[sum]);}
	else {mp_f[sum]=i;}
	}
	cout<<ans;
}