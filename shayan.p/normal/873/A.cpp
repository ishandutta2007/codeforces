#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define S second
#define F first
#define PB push_back
#define MP make_pair
using namespace std;
int main()
{
	ll n,k,x,s=0;cin>>n>>k>>x;ll a[n+10];
	for(ll i=n-1;i>=0;i--) cin>>a[i];
	for(ll i=0;i<n;i++) s+=(i<k)?x:a[i];
	cout<<s;
}