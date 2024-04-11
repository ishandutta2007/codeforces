#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
ll argham(ll num){
	ll ten=1;
	while(num>0){
		ten*=10;
		num/=10;
	}
	return ten;
}
ll f(ll num){
	ll t=argham(num);
	ll ans=num*t;
	t/=10;
	while(num>0){
		ans+=t*(num%10);
		t/=10;
		num/=10;
	}
	return ans;
}
int main(){
	ll k,p,ans=0;cin>>k>>p;
	for(ll i=1;i<=k;i++){
		ans=(ans+f(i))%p;
	}
	cout<<ans;
}