#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll , ll> pll;

const ll MAX_N = 2e5 + 20;

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
	}
	return res;
}

void solve(){
	ll n , x = 0 , k = 0;
	cin>>n;
	while(x < n){
		x += ++k;
	}
	if(n == x - 1){
		cout<<k + 1<<'\n';
		return;
	}
	cout<<k<<'\n';
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