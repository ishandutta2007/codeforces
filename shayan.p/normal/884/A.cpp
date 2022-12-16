#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll s=0,n,t;cin>>n>>t;ll a[n+10];
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++) {s+=(86400-a[i]); if(s>=t) {cout<<i;return 0;} }
}