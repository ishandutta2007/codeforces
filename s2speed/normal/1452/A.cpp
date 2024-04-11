#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 0;

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return x * x;
	} else {
		return x * x * n;
	}
}

void solve(){
	ll a , b , z = 0 , ans = 0;
	cin>>a>>b;
	if(a < b){
		swap(a , b);
	}
	ans = a + b;
	z = a - 1;
	z = max(z - b , 0LL);
	ans += z;
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}