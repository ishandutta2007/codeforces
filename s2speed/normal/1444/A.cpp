#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

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

vector<ll> v;

void solve(){
	ll p , q , ans = 1;
	cin>>p>>q;
	if(p % q != 0){
		cout<<p<<"\n";
		return;
	}
	double sq = sqrt(q);
	for(int i = 2 ; i <= sq ; i++){
		if(q % i == 0){
			v.push_back(i);
			if(i != sq){
				v.push_back(q / i);
			}
		}
	}
	v.push_back(q);
	ll vs = v.size();
	for(ll i = 0 ; i < vs ; i++){
		ll h = v[i] , x = p;
		while(x % q == 0){
			x /= h;
		}
		ans = max(ans , x);
	}
	cout<<ans<<"\n";
	v.clear();
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}