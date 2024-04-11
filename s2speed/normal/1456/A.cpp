#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

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

vector<ll> e[MAX_N];
ll m[MAX_N];

void solve(){
	ll n , p , k , ans = 1e18 , x , y;
	string s;
	cin>>n>>p>>k>>s>>x>>y;
	for(ll i = 0 ; i < k ; i++){
		e[i].clear();
		e[i].push_back(s[i] == '0');
	}
	for(int i = k ; i < n ; i++){
		e[i % k].push_back(e[i % k][i / k - 1] + (s[i] == '0'));
	}
	for(int i = n - 1 ; i >= n - k ; i--){
		m[i % k] = e[i % k][i / k];
	}
	for(int i = p - 1 ; i < n ; i++){
		ll h = (i - p + 1) * y , q;
		q = m[i % k];
		if(i / k > 0){
			q -= e[i % k][i / k - 1];
		}
		q *= x;
		ans = min(h + q , ans);
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