#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
ll one,two;
int main(){
	ll n;cin>>n;
	ll ans=0;
	for(ll i=0;i<n;i++){
		ll x;cin>>x;
		if(x==1)one++;
		else two++;
	}
	ans+=min(one,two);
	one-=ans;
	two-=ans;
	ans+=one/3;
	cout<<ans;
}