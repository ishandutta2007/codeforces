#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp make_pair
#define wall cout<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e2 + 16 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

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

bitset<maxn> mark;
vector<ll> v;
vector<pll> ed;

void solve(){
	ed.clear(); v.clear(); mark.reset();
	ll n , k , f;
	cin>>n>>k; f = n - k;
	for(ll i = 0 ; i < k ; i++){
		ll a , b;
		cin>>a>>b; a--; b--;
		if(a > b) swap(a , b);
		ed.push_back({a , b});
		mark[a] = mark[b] = true;
	}
	for(ll i = 0 ; i < 2 * n ; i++){
		if(mark[i]) continue;
		v.push_back(i);
	}
	for(ll i = 0 ; i < f ; i++){
		ed.push_back({v[i] , v[i + f]});
	}
	ll ans = 0;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = i + 1 ; j < n ; j++){
			bool ch = false;
			ll a , b , c , d;
			a = ed[i].first; b = ed[i].second; c = ed[j].first; d = ed[j].second;
			if(a > c && a < d && b > d) ch = true;
			if(b > c && b < d && a < c) ch = true;
			ans += ch;
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}