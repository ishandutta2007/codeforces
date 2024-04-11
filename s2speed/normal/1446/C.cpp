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

vector<ll> v;
ll n;

ll dp(ll l , ll r , ll h){
	if(r - l <= 3 || h <= 0){
		return 0;
	}
	ll m = r;
	for(int i = l ; i < r ; i++){
		ll z = v[i] & h;
		if(z == 0){
			m = i;
			break;
		}
	}
	ll dp1 , dp2 , d1 , d2 , ans;
	d1 = max(0LL , m - l - 1);
	d2 = max(0LL , r - m - 1);
	dp1 = dp(l , m , h / 2);
	dp2 = dp(m , r , h / 2);
	ans = min(dp1 + d2 , dp2 + d1);
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll h = 1 << 29;
	cin>>n;
	v.resize(n);
	for(int i = 0 ; i < n ; i++){
		cin>>v[i];
	}
	sort(v.begin() , v.end() , greater<ll>());
	cout<<dp(0 , n , h)<<"\n";
	return 0;
}