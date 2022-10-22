#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e5 + 16 , maxsq = 31700 , inf = 2e17;
ll md , fi;

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

bitset<maxsq> gh;
vector<ll> pr;

void prime(){
	gh.set();
	for(ll i = 2 ; i < maxsq ; i++){
		if(gh[i]){
			pr.push_back(i);
			for(ll j = i * i ; j < maxsq ; j += i) gh[j] = false;
		}
	}
	return;
}

struct sugtree {

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
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a;
		if(i < m){
			a = cal(i , ln , lx , m);
		} else {
			a = cal(i , rn , m , rx);
		}
		return a + val[x];
	}

	ll cal(ll i){
		return cal(i , 0 , 0 , sz);
	}

};

struct segtree {

	ll sz = 1;
	pll def = {1 , 0};
	vector<ll> val;
	vector<pll> laz;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , 0);
		laz.assign(sz << 1 , def);
		return;
	}

	void shift(ll x , ll lx , ll rx){
		if(laz[x] == def) return;
		pll h = laz[x];
		laz[x] = def;
		val[x] *= h.first; val[x] %= md;
		val[x] += h.second; val[x] %= md;
		if(rx - lx == 1) return;
		ll ln = (x << 1) + 1 , rn = ln + 1;
		laz[ln].first *= h.first; laz[ln].first %= md;
		laz[ln].second *= h.first; laz[ln].second %= md;
		laz[ln].second += h.second; laz[ln].second %= md;

		laz[rn].first *= h.first; laz[rn].first %= md;
		laz[rn].second *= h.first; laz[rn].second %= md;
		laz[rn].second += h.second; laz[rn].second %= md;
		return;
	}

	void add(ll l , ll r , pll p , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			laz[x] = p;
			shift(x , lx , rx);
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		add(l , r , p , ln , lx , m); add(l , r , p , rn , m , rx);
		val[x] = val[ln] + val[rn]; val[x] %= md;
		return;
	}

	void add(ll l , ll r , pll p){
		add(l , r , p , 0 , 0 , sz);
		return;
	}

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return 0;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a;
		a = cal(l , r , ln , lx , m) + cal(l , r , rn , m , rx);
		if(a >= md) a %= md;
		return a;
	}

	ll cal(ll l , ll r){
		return cal(l , r , 0 , 0 , sz);
	}

};

vector<ll> p;
ll ps;

void phi(){
	ll h = md;
	for(auto i : pr){
		if(h % i == 0) p.push_back(i);
		while(h % i == 0) h /= i;
	}
	if(h != 1) p.push_back(h);
	fi = 0;
	ps = sze(p);
	ll lm = (1 << ps);
	for(ll mask = 0 ; mask < lm ; mask++){
		ll cnt = 0 , h = 1;
		for(ll j = 0 ; j < ps ; j++){
			cnt += (bool)(mask & (1 << j));
			if(mask & (1 << j)){
				h *= p[j];
			}
		}
		fi += (1 - ((cnt & 1) << 1)) * (md / h);
	}
	return;
}

sugtree st[10];
segtree zt , gt;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	prime();
	ll n , q;
	cin>>n>>md;
	phi();
	for(ll i = 0 ; i < ps ; i++) st[i].init(n);
	zt.init(n); gt.init(n);
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		zt.add(i , i + 1 , {0 , h});
		for(ll j = 0 ; j < ps ; j++){
			ll cnt = 0;
			while(h % p[j] == 0){
				cnt++;
				h /= p[j];
			}
			st[j].add(i , i + 1 , cnt);
		}
		gt.add(i , i + 1 , {0 , h});
	}
	cin>>q;
	for(ll e = 0 ; e < q ; e++){
		ll t;
		cin>>t;
		if(t == 3){
			ll l , r;
			cin>>l>>r; l--;
			cout<<zt.cal(l , r)<<'\n';
		}
		if(t == 1){
			ll l , r , x;
			cin>>l>>r>>x; l--;
			zt.add(l , r , {x , 0});
			for(ll j = 0 ; j < ps ; j++){
				ll i = p[j] , cnt = 0;
				while(x % i == 0){
					cnt++;
					x /= i;
				}
				st[j].add(l , r , cnt);
			}
			gt.add(l , r , {x , 0});
		}
		if(t == 2){
			ll i , x;
			cin>>i>>x; i--;
			zt.add(i , i + 1 , {0 , 0});
			for(ll j = 0 ; j < ps ; j++){
				ll h = p[j] , cnt = 0;
				while(x % h == 0){
					cnt++;
					x /= h;
				}
				st[j].add(i , i + 1 , -cnt);
			}
			gt.add(i , i + 1 , {tav(x , fi - 1) , 0});
			ll h = gt.cal(i , i + 1);
			for(ll j = 0 ; j < ps ; j++){
				ll o = tav(p[j] , st[j].cal(i));
				h *= o; h %= md;
			}
			zt.add(i , i + 1 , {0 , h});
		}
	}
	return 0;
}