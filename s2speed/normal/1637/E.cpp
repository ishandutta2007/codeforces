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

const ll maxn = 3e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll a[maxn] , cnt[maxn];
vector<ll> v , b[maxn] , u , p[maxn];
set<pll> w;
bitset<maxn> ch;

void solve(){
	v.clear(); u.clear(); w.clear();
	ll n , m , sq;
	cin>>n>>m; sq = min(550ll , n);
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		v.push_back(a[i]);
		b[i].clear(); b[i].push_back(i);
	}
	for(ll i = 1 ; i <= sq ; i++) p[i].clear(); 
	sort(all(v));
	v.resize(distance(v.begin() , unique(all(v))));
	ll vs = sze(v);
	for(ll i = 0 ; i < n ; i++){
		a[i] = lower_bound(all(v) , a[i]) - v.begin();
		cnt[a[i]]++;
	}
	for(ll i = 0 ; i < m ; i++){
		ll x , y;
		cin>>x>>y;
		ll jx = lower_bound(all(v) , x) - v.begin() , jy = lower_bound(all(v) , y) - v.begin();
		w.insert({jx , jy}); w.insert({jy , jx});
		b[jx].push_back(jy); b[jy].push_back(jx);
	}
	for(ll i = vs - 1 ; ~i ; i--){
		if(cnt[i] > sq){
			u.push_back(i);
		} else {
			p[cnt[i]].push_back(i);
		}
	}
	ll us = sze(u) , ans = 0;
	for(ll e = 0 ; e < us ; e++){
		for(ll t = e + 1 ; t < us ; t++){
			ll i = u[e] , j = u[t];
			if(w.count({i , j})) continue;
			ans = max(ans , 1ll * (cnt[i] + cnt[j]) * (v[i] + v[j]));
		}
	}
	for(ll i = 0 ; i < vs ; i++){
		for(auto j : b[i]) ch[j] = true;
		for(ll j = 1 ; j <= sq ; j++){
			ll ps = sze(p[j]) , x = 0;
			while(true){
				if(x == ps) break;
				ll k = p[j][x];
				if(ch[k]){
					x++;
					continue;
				}
				ans = max(ans , 1ll * (cnt[i] + j) * (v[i] + v[k]));
				break;
			}
		}
		for(auto j : b[i]) ch[j] = false;
	}
	for(ll i = 0 ; i < n ; i++) cnt[a[i]]--;
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}