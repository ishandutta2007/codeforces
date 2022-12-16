#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
const ll maxn=200;
ll a[maxn];
int main(){
	ll n;cin>>n;
	ll state=0;
	for(ll i=0;i<n;i++)cin>>a[i];
	ll i=1;
	while(i<n&&a[i-1]<a[i])i++;
	while(i<n&&a[i-1]==a[i])i++;
	while(i<n&&a[i-1]>a[i])i++;
	if(i==n)cout<<"YES";
	else cout<<"NO";
}