#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
ll other(ll a,ll b)
{
	if(1!=a&&1!=b)return 1;
	if(2!=a&&2!=b)return 2;
	if(3!=a&&3!=b)return 3;
}
int main()
{
	ll n;cin>>n;
	ll sp=3;
	bool no=0;
	for(ll i=0;i<n;i++){
		ll x;cin>>x;
		if(x==sp)no=1;
		sp=other(x,sp);
	}
	if(no)cout<<"NO";
	else cout<<"YES";
}