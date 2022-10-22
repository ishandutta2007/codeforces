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
	ll n , q;
	string s;
	cin>>n>>q>>s;
	while(q--){
		ll l , r;
		cin>>l>>r; l--;
		ll y = l , c = 0;
		for(int x = 0 ; x < n && y < r ; x++){
			if(c == (r - l - 1)){
				c = 0;
			} else if(s[x] == s[y]){
				c++;
				y++;
			} else {
				c = 0;
			}
		}
		if(y == r){
			cout<<"YES\n";
		} else {
			cout<<"NO\n";
		}
	}
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