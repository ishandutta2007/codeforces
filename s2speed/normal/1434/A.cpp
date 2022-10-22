#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 1e5;

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

ll x[MAX_N] , m = 0 , a[MAX_N][6] , p = -1;
vector< pair<ll , ll> > v;
vector<ll> b;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll ans = 1e18;
	b.resize(6);
	for(int i = 0 ; i < 6 ; i++){
		cin>>b[i];
	}
	sort(b.begin() , b.end() , greater<ll>());
	ll n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		x[i] = 0;
		ll inp;
		cin>>inp;
		for(int j = 0 ; j < 6 ; j++){
			a[i][j] = inp - b[j];
			v.push_back( {a[i][j] , i} );
		}
	}
	sort(v.begin() , v.end());
	for(int i = 0 ; i < n ; i++){
		m = max(m , a[i][0]);
	}
	ll u = v[0].second;
	for(int i = 0 ; x[u] < 6 ; i++){
		ll h = v[i].first , q = m - h , o = v[i].second;
		x[o]++;
		m = max(m , a[o][x[o]]);
		if(h == p){
			continue;
		}
		ans = min(ans , q);
		p = h;
	}
	cout<<ans<<"\n";
	return 0;
}