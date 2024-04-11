#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
int main(){
	ll n;cin>>n;
	ll a=0,b=0;
	for(ll i=0;i<n;i++){
		ll x,y;cin>>x>>y;
		if(x<0)a++;
		else b++;
	}
	if(a<=1||b<=1)cout<<"Yes";
	else cout<<"No";
}