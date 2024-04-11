#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll , ll> pll;

const ll MAX_N = 510;

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

ll m[MAX_N] , x[MAX_N] , a[MAX_N];

void solve(){
	ll n , h;
	cin>>n>>h;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(int i = 0 ; i <= 500 ; i++){
		x[i] = 1000 * (i != h);
	}
	m[n - 1] = a[n - 1];
	for(int i = n - 2 ; i >= 0 ; i--){
		m[i] = min(a[i] , m[i + 1]);
	}
	for(int i = 0 ; i < n ; i++){
		if(a[i] <= m[i]){
			if(i == 0){
				if(h < a[i]){
					x[a[i]] = 1;
				}
			} else{
				for(int j = a[i - 1] ; j < a[i] ; j++){
					x[a[i]] = min(x[a[i]] , x[j] + 1);
				}
			}
		} else {
			ll q = 1000;
			if(i == 0){
				if(h <= m[i]){
					q = 1;
				}
			} else {
				for(int j = a[i - 1] ; j <= m[i] ; j++){
					q = min(q , x[j] + 1);
				}
			}
			for(int j = 0 ; j <= 500 ; j++){
				x[j] = 1000;
			}
			x[a[i]] = q;
		}
	}
	ll ans = 1000;
	for(int i = 0 ; i <= 500 ; i++){
		ans = min(ans , x[i]);
	}
	if(ans > 500){
		cout<<"-1\n";
		return;
	}
	cout<<ans<<'\n';
}

/*
1
4 500
0 499 500 499
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}