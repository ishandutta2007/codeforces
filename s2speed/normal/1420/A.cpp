#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 5e4;

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
	bool ans = false;
	ll n , h , q;
	cin>>n>>h;
	for(int i = 1 ; i < n ; i++){
		cin>>q;
		if(q >= h){
			ans = true;
		}
		swap(h , q);
	}
	if(ans){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
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