#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
 
const int MAX_N = 2e5 + 20;
 
int tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
		k /= 2;
	}
	return res;
}

bool mark[108];

void solve(){
	ll n , m , ans = 0;
	cin>>n>>m;
	for(int i = 0 ; i < 100 ; i++){
		mark[i] = false;
	}
	for(int i = 0 ; i < n ; i++){
		ll u;
		cin>>u; u--;
		mark[u] = true;
	}
	for(int i = 0 ; i < m ; i++){
		ll u;
		cin>>u; u--;
		ans += mark[u];
	}
	cout<<ans<<'\n';
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