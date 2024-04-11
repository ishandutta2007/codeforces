#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")
 
#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e2 + 16 , md = 1e9 + 7 , inf = 2e18;

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k >>= 1;
	}
	return res;
}

vector<ll> u;
vector<pll> v;
ll ans[maxn];

void solve(){ v.clear();
	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < m ; i++){
		ll h;
		cin>>h;
		v.push_back({h , -1});
	}
	sort(all(v));
	for(ll i = 0 ; i < m ; i++){
		cout<<v[i].first<<' ';
		v[i].second = i;
	}
	cout<<'\n';
	for(ll i = 1 ; i < n ; i++){
		u.resize(m);
		for(ll j = 0 ; j < m ; j++){
			cin>>u[j];
		}
		sort(all(u));
		sort(all(v) , greater<pll>());
		for(ll j = 0 ; j < m ; j++){
			ans[v[j].second] = u[j];
			if(v[j].first <= u[j]) continue;
			v[j].first = u[j];
		}
		u.clear();
		for(ll j = 0 ; j < m ; j++){
			cout<<ans[j]<<' ';
		}
		cout<<'\n';
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}