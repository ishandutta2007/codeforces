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
	ll n;cin>>n;ll b[n+10];
	ll sum=0;
	for(ll i=0;i<n;i++){ll x;cin>>x;sum+=x;}
	for(ll i=0;i<n;i++)cin>>b[i];
	sort(b,b+n,greater<ll>());
	if(sum<=b[0]+b[1])cout<<"YES";
	else cout<<"NO";
}