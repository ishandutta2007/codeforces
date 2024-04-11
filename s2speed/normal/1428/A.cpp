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

ll gh(ll a , ll b){
	ll h = a - b;
	if(h < 0){
		h = 0 - h;
	}
	return h;
}

void solve(){
	ll a , b , c , d , ans = 0;
	cin>>a>>b>>c>>d;
	ans += gh(a , c);
	ans += gh(b , d);
	if(a != c && b != d){
		ans += 2;
	}
	cout<<ans<<"\n";
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