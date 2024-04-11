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
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e6 + 16 , md = 1e9 + 7 , inf = 2e16;

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

struct segtree {

	ll sz = 1;
	vector<ll> val;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , 0);
		return;
	}

	void add(ll l , ll r , ll k , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			val[x] += k;
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		add(l , r , k , ln , lx , m); add(l , r , k , rn , m , rx);
		return;
	}

	void add(ll l , ll r , ll k){
		add(l , r , k , 0 , 0 , sz);
		return;
	}

	ll cal(ll i , ll x , ll lx , ll rx){
		if(rx - lx == 1) return val[x];
		ll a;
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(i < m){
			a = cal(i , ln , lx , m);
		} else {
			a = cal(i , rn , m , rx);
		}
		return val[x] + a;
	}

	ll cal(ll i){
		return cal(i , 0 , 0 , sz);
	}

};

segtree st;
ll ps[maxn];
vector<pll> ht[maxn];
set<plll> s;
vector<plll> del;
vector<ll> ind;

void add(ll l , ll r , ll t , ll c){
	del.clear(); ind.clear();
	auto it = s.upper_bound({l , {t , c}}); it--;
	while((*it).first < r){
		del.push_back(*it);
		ind.push_back((*it).first);
		it++;
	}
	ind.push_back((*it).first);
	for(auto q : del){
		s.erase(q);
	}
	if(del[0].first < l){
		s.insert({del[0].first , {t , del[0].second.second}});
	}
	if((*it).first > r){
		s.insert({r , {t , del.back().second.second}});
	}
	s.insert({l , {t , c}});
	ll ds = sze(del);
	for(ll e = 0 ; e < ds ; e++){
		ll l = ind[e] ,  r = ind[e + 1] , t = del[e].second.first , c = del[e].second.second;
		ll j = lower_bound(all(ht[c]) , mp(t , inf)) - ht[c].begin() - 1;
		ll h = ps[c] - ht[c][j].second;
//		cout<<l<<' '<<r<<' '<<h<<' '<<ps[c]<<' '<<t<<' '<<j<<'\n';
		st.add(l , r , h);
	}
	return;
}

ll que(ll i){
	ll res = st.cal(i);
	auto it = s.upper_bound({i , {inf , inf}}); it--;
	ll t = (*it).second.first , c = (*it).second.second;
	ll j = lower_bound(all(ht[c]) , mp(t , inf)) - ht[c].begin() - 1;
	ll h = ps[c] - ht[c][j].second;
	res += h;
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(ps , 0 , sizeof(ps));
	ll n , q;
	cin>>n>>q;
	for(ll i = 0 ; i < n ; i++) ht[i].push_back({-1 , 0});
	st.init(n);
	s.insert({0 , {-1 , 0}}); s.insert({n , {inf , -1}});
	for(ll e = 0 ; e < q ; e++){
		string s;
		cin>>s;
		if(s[0] == 'C'){
			ll l , r , c;
			cin>>l>>r>>c; l--; c--;
			add(l , r , e , c);
		} else if(s[0] == 'Q'){
			ll i;
			cin>>i; i--;
			cout<<que(i)<<'\n';
		} else {
			ll c , k;
			cin>>c>>k; c--;
			ps[c] += k;
			ht[c].push_back({e , ps[c]});
		}
	}
	return 0;
}

/*
5 3
Color 2 4 2
Add 2 2
Query 3
Color 4 5 3
Color 2 2 3
Add 3 3
Query 2
Query 5
*/