#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 2e5 + 15 , MAX = 1e6 + 15 , md = 998244353 , inf = 1e15;
// check problem statement

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k /= 2;
	}
	return res;
}

vector<ll> v , ps , m;

void solve(){
	v.clear(); ps.clear(); m.clear();
	ll n , q;
	cin>>n>>q;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		v.push_back(h);
	}
	ps.resize(n + 1); m.resize(n + 1);
	ps[0] = v[0]; m[0] = ps[0];
	for(ll i = 1 ; i < n ; i++){
		ps[i] = ps[i - 1] + v[i];
		m[i] = max(m[i - 1] , ps[i]);
	}
	m[n] = m[n - 1]; ps[n] = ps[n - 1];
	while(q){
		q--;
		ll x , ans = 0;
		cin>>x;
		if(x <= m[n]){
			ans = lower_bound(all(m) , x) - m.begin();
			cout<<ans<<' ';
			continue;
		}
		x -= m[n];
		if(ps[n] <= 0){
			cout<<"-1 ";
			continue;
		}
		ans = 1ll * (x + ps[n] - 1) / ps[n] * n;
		x %= ps[n]; x -= ps[n]; x %= ps[n]; x += m[n];
		ans += lower_bound(all(m) , x) - m.begin();
		cout<<ans<<' ';
	}
	cout<<'\n';
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

/*

*/