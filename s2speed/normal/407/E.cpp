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
typedef pair<pll , ll> plll;
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;

struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
 
const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e18;

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

ll n , k , d;

struct segtree {

	ll sz = 1;
	vector<ll> ax[2] , an[2] , val , lvz , laz[2];

	void init(ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x] = lx - n;
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		init(ln , lx , m); init(rn , m , rx);
		val[x] = val[ln];
		return;
	}

	void init(ll n){
		while(sz < n) sz <<= 1;
		ax[0].assign((sz << 1) , 0);
		an[0].assign((sz << 1) , 0);
		ax[1].assign((sz << 1) , 0);
		an[1].assign((sz << 1) , 0);
		val.assign((sz << 1) , 0);
		laz[0].assign((sz << 1) , -1);
		laz[1].assign((sz << 1) , -1);
		init(0 , 0 , sz);
		return;
	}

	void shift(ll x , ll lx , ll rx){
		ll h[] = {laz[0][x] , laz[1][x]};
		laz[0][x] = laz[1][x] = -1;
		ll ln = (x << 1) + 1 , rn = ln + 1;
		if(h[0] != -1){
			val[x] += (h[0] - ax[0][x]);
			an[0][x] = ax[0][x] = h[0];
			if(rx - lx > 1){
				laz[0][ln] = laz[0][rn] = h[0];
			}
		}
		if(h[1] != -1){
			val[x] += (ax[1][x] - h[1]);
			an[1][x] = ax[1][x] = h[1];
			if(rx - lx > 1){
				laz[1][ln] = laz[1][rn] = h[1];
			}
		}
		return;
	}

	void set(ll l , ll r , ll k , bool c , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l && ax[c][x] == an[c][x]){
			laz[c][x] = k;
			shift(x , lx , rx);
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		set(l , r , k , c , ln , lx , m); set(l , r , k , c , rn , m , rx);
		an[0][x] = min(an[0][ln] , an[0][rn]);
		an[1][x] = min(an[1][ln] , an[1][rn]);
		ax[0][x] = max(ax[0][ln] , ax[0][rn]);
		ax[1][x] = max(ax[1][ln] , ax[1][rn]);
		val[x] = min(val[ln] , val[rn]);
		return;
	}

	void set(ll l , ll r , ll k , bool c){
		set(l , r , k , c , 0 , 0 , sz);
		return;
	}

	ll cal(ll l , ll r , ll k , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return -1;
		if(val[x] > k) return -1;
		if(rx - lx == 1) return lx;
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a = cal(l , r , k , ln , lx , m);
		if(a != -1) return a;
		return cal(l , r , k , rn , m , rx);
	}

	ll cal(ll l , ll r , ll k){
		return cal(l , r , k , 0 , 0 , sz);
	}

};

segtree st;
ll a[maxn] , b[maxn];
unordered_map<ll , ll , custom_hash> t;
vector<pll> in , de;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>k>>d;
	if(!d){
		ll l = 0 , ans = 1 , ind = 0;
		cin>>a[0];
		for(ll i = 1 ; i < n ; i++){
			cin>>a[i];
			if(a[i] != a[i - 1]){
				if(i - l > ans){
					ind = l;
					ans = i - l;
				}
				l = i;
			}
		}
		if(n - l > ans){
			ind = l;
			ans = n - l;
		}
		cout<<ind + 1<<' '<<ind + ans<<'\n';
		return 0;
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i] += 1e9;
		b[i] = a[i] / d;
	}
	st.init(n);
	ll l = 0 , ans = 1 , ind = 0;
	for(ll i = 0 ; i < n ; i++){
		if(i){
			if(a[i] % d != a[i - 1] % d) l = i;
		}
		if(t.count(a[i])){
			l = max(l , t[a[i]] + 1);
		}
		t[a[i]] = i;
		ll h = 0;
		while(!in.empty()){
			pll p = in.back();
			ll o = p.first , j = p.second;
			if(o <= b[i]){
				h = j + 1;
				break;
			}
			in.pop_back();
		}
		in.push_back({b[i] , i});
		st.set(h , i + 1 , b[i] , 1);
		h = 0;
		while(!de.empty()){
			pll p = de.back();
			ll o = p.first , j = p.second;
			if(o >= b[i]){
				h = j + 1;
				break;
			}
			de.pop_back();
		}
		de.push_back({b[i] , i});
		st.set(h , i + 1 , b[i] , 0);
		ll o = i - st.cal(l , i + 1 , k - n + i) + 1;
		if(o > ans){
			ind = i;
			ans = o;
		}
	}
	cout<<ind - ans + 2<<' '<<ind + 1<<'\n';
	return 0;
}