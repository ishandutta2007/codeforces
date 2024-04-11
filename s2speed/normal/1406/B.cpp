#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

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

vector<ll> v[2];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		ll n , ans = -1e18 , m = 1;
		cin>>n;
		ll h;
		for(int i = 0 ; i < n ; i++){
			cin>>h;
			if(h <= 0){
				v[0].push_back(h);
			} else {
				v[1].push_back(h);
			}
		}
		sort(v[0].begin() , v[0].end()); sort(v[1].begin() , v[1].end() , greater<ll>());
		if(n == 5){
			ll v1s = v[1].size() , v0s = v[0].size();
			for(int i = 0 ; i < v1s ; i++){
				m *= v[1][i];
			}
			for(int i = 0 ; i < v0s ; i++){
				m *= v[0][i];
			}
			cout<<m<<"\n";
			v[0].clear(); v[1].clear();
			continue;
		}
		if(v[1].size() == 0){
			ll vs = v[0].size();
			for(int i = vs - 1 ; i >= vs - 5 ; i--){
				m *= v[0][i];
			}
			cout<<m<<"\n";
			v[0].clear(); v[1].clear();
			continue;
		}
		if(v[1].size() >= 5){
			for(int i = 0 ; i < 5 ; i++){
				m *= v[1][i];
			}
			ans = max(m , ans);
		}
		m = 1;
		if(v[1].size() >= 3 && v[0].size() >= 2){
			for(int i = 0 ; i < 3 ; i++){
				m *= v[1][i];
			}
			for(int i = 0 ; i < 2 ; i++){
				m *= v[0][i];
			}
			ans = max(m , ans);
		}
		m = 1;
		if(v[0].size() >= 4){
			m *= v[1][0];
			for(int i = 0 ; i < 4 ; i++){
				m *= v[0][i];
			}
			ans = max(m , ans);
		}
		m = 1;
		cout<<ans<<"\n";
		v[0].clear();
		v[1].clear();
	}
	return 0;
}