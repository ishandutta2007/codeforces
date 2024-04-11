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
	ll n , k , h = 0;
	cin>>n>>k;
	for(int i = 0 ; i < n ; i++){
		ll inp;
		cin>>inp;
		h += inp;
		if(h >= 8){
			k -= 8;
			h -= 8;
		} else {
			k -= h;
			h = 0;
		}
		if(k <= 0){
			cout<<(i + 1)<<"\n";
			return;
		}
	}
	cout<<"-1\n";
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	solve();
	return 0;
}