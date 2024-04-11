#include<bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ll long long
using namespace std;
int main()
{
	ll n,ans=0;cin>>n;ll a[n+10];
	for(ll i=0;i<n;i++)cin>>a[i];
	for(ll i=1;i<n-1;i++)if((a[i]>a[i-1]&&a[i]>a[i+1])||(a[i]<a[i-1]&&a[i]<a[i+1]))ans++;
	cout<<ans;
}