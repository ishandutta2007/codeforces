#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 2e5;

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
	ll n , ans = 0 , q = 1e9;
	cin>>n;
	v.resize(n);
	for(int i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		h--;
		v[h]++;
	}
	sort(v.begin() , v.end() , greater<ll>());
	for(int i = 0 ; i < n ; i++){
		if(q <= 0){
			break;
		}
		ans += min(v[i] , q);
		q = min(v[i] , q) - 1;
	}
	cout<<ans<<"\n";
	v.clear();
	return;
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