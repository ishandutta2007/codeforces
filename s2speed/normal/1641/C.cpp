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

struct segtree {

	ll sz = 1;
	vector<ll> val;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , -inf);
		return;
	}

	void set(ll i , ll k , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x] = max(val[x] , k);
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(i < m){
			set(i , k , ln , lx , m);
		} else {
			set(i , k , rn , m , rx);
		}
		val[x] = max(val[ln] , val[rn]);
		return;
	}

	void set(ll i , ll k){
		set(i , k , 0 , 0 , sz);
		return;
	}

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return -inf;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a = cal(l , r , ln , lx , m) , b = cal(l , r , rn , m , rx);
		return max(a , b);
	}

	ll cal(ll l , ll r){
		return cal(l , r , 0 , 0 , sz);
	}

};

segtree st;
set<ll> s;
vector<ll> del;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , q;
	cin>>n>>q;
	s.insert(-1);
	for(ll i = 0 ; i < n ; i++){
		s.insert(i);
	}
	s.insert(n);
	st.init(n);
	for(ll e = 0 ; e < q ; e++){
		ll t;
		cin>>t;
		if(!t){
			ll l , r , x;
			cin>>l>>r>>x; l--;
			if(x){
				st.set(r , l);
			} else {
				auto it = s.lower_bound(l);
				while(*it < r){
					del.push_back(*it);
					it++;
				}
				for(auto j : del) s.erase(j);
				del.clear();
			}
		} else {
			ll i;
			cin>>i; i--;
			if(!s.count(i)){
				cout<<"NO\n";
				continue;
			}
			auto it = s.upper_bound(i);
			ll r = *it , l;
			it--; it--;
			l = *it;
			ll h = st.cal(i + 1 , r + 1);
//			cout<<l<<' '<<r<<' '<<h<<'\n';
			if(h > l){
				cout<<"YES\n";
			} else {
				cout<<"N/A\n";
			}
		}
	}
	return 0;
}

/*
6 5
0 4 5 0
1 5
1 6
0 4 6 1
1 6
*/