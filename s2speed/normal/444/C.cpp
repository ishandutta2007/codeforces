#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast,unroll-loops")

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

const ll MAXN = 1e5 + 20 , md = 1e9 + 7 , inf = 5e18;
// check problem statement

struct segtree {

	ll sz = 1;
	vector<ll> val , laz;

	void init(ll n){
		while(sz < n) sz *= 2;
		val.assign(2 * sz , 0);
		laz.assign(2 * sz , 0);
		return;
	}

	void shift(ll x , ll lx , ll rx){
		if(laz[x] == 0) return;
		ll h = laz[x];
		laz[x] = 0;
		val[x] += 1ll * (rx - lx) * h;
		if(rx - lx == 1) return;
		ll ln = 2 * x + 1 , rn = ln + 1;
		laz[ln] += h; laz[rn] += h;
		return;
	}

	void add(ll l , ll r , ll k , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			laz[x] = k;
			shift(x , lx , rx);
			return;
		}
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		add(l , r , k , ln , lx , m); add(l , r , k , rn , m , rx);
		val[x] = val[ln] + val[rn];
		return;
	}

	void add(ll l , ll r , ll k){
		if(l >= r) return;
		add(l , r , k , 0 , 0 , sz);
		return;
	}

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return 0;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		ll a , b;
		a = cal(l , r , ln , lx , m);
		b = cal(l , r , rn , m , rx);
		return a + b;
	}

	ll cal(ll l , ll r){
		if(l >= r) return 0;
		return cal(l , r , 0 , 0 , sz);
	}

};

segtree st;
set<pll> s;
vector<pll> del;

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , q;
	cin>>n>>q;
	s.insert({0 , -1});
	for(int i = 1 ; i <= n ; i++){
		s.insert({i , i});
	}
	st.init(n);
	for(int g = 0 ; g < q ; g++){
		ll t;
		cin>>t;
		if(t == 2){
			ll l , r;
			cin>>l>>r; l--;
			cout<<st.cal(l , r)<<'\n';
			continue;
		}
		if(t == 1){
			ll l , r , k , h , v , i;
			pll p , u;
			cin>>l>>r>>k; l--;
			set<pll>::iterator o = s.upper_bound({l , inf}) , e;
			e = o; e--;
			u = *o;
			p = *o;
			h = l;
			i = p.first;
			v = p.second;
			while(i <= r){
				del.push_back(p);
				st.add(h , i , max(k - v , v - k));
				h = i;
				o++;
				if(o == s.end()) break;
				p = *o;
				i = p.first;
				v = p.second;
			}
			st.add(h , r , max(k - p.second , p.second - k));
			for(auto y : del){
				s.erase(y);
			}
			del.clear();
			pll y = *e;
			if(l != y.first){
				s.insert({l , u.second});
			}
			s.insert({r , k});
		}
	}
	return 0;
}

/*
3 2

1 2 3 5
2 1 3
*/