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

void solve(){
	ll l , r , x , y , k;
	cin>>l>>r>>x>>y>>k;
	x *= k; y *= k;
	if(r < x || l > y || (l % k != 0 && l / k == r / k)){
		cout<<"NO\n";
	} else {
		cout<<"YES\n";
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	solve();
	return 0;
}