#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cerr<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , md = 998244353 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

inline ll tav(ll n , ll k){
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

set<ll> s;
ll a[maxn];
vector<pll> ad;
vector<ll> t , v;

void solve(){
	s.clear();
	ad.clear(); t.clear();
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		if(s.count(a[i])){
			s.erase(a[i]);
		} else {
			s.insert(a[i]);
		}
	}
	if(!s.empty()){
		cout<<"-1\n";
		return;
	}
	ll pi = 0 , cur = 1;
	for(ll i = 1 ; i < n ; i++){
		if(a[i] != a[pi]){
			cur++;
			continue;
		}
		t.push_back(2 * (i - pi));
		v.clear();
		for(ll j = pi + 1 ; j < i ; j++){
			v.push_back(a[j]);
		}
		ll vs = sze(v);
		for(ll e = 0 ; e < vs ; e++){
			ad.push_back({++cur , v[e]});
		}
		reverse(all(v));
		for(ll j = pi + 2 ; j <= i ; j++){
			a[j] = v[j - pi - 2];
		}
		pi += 2;
		i = pi;
		cur += 2;
	}
	cout<<sze(ad)<<'\n';
	for(auto p : ad){
		cout<<p.first<<' '<<p.second<<'\n';
	}
	cout<<sze(t)<<'\n';
	for(auto i : t){
		cout<<i<<' ';
	}
	cout<<'\n';
	return;
}

/*
1
6
1 3 1 2 2 3
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}