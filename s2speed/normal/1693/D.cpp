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

const ll maxn = 2e5 + 17 , md = 1e9 + 7 , inf = 2e16;

struct segtree {

	ll sz = 1;
	vector<ll> val;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , inf);
		return;
	}

	void set(ll i , ll k , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x] = k;
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(i < m){
			set(i , k , ln , lx , m);
		} else {
			set(i , k , rn , m , rx);
		}
		val[x] = min(val[ln] , val[rn]);
		return;
	}

	void set(ll i , ll k){
		set(i , k , 0 , 0 , sz);
		return;
	}

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return inf;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a , b;
		a = cal(l , r , ln , lx , m);
		b = cal(l , r , rn , m , rx);
		return min(a , b);
	}

	ll cal(ll l , ll r){
		if(l >= r) return inf;
		return cal(l , r , 0 , 0 , sz);
	}

	void clear(){
		sz = 1;
		val.clear();
	}

};

segtree sk , sb;
ll a[maxn] , p[maxn];
ll rk[maxn] , rb[maxn] , lk[maxn] , lb[maxn] , f[maxn];
vector<ll> v , vk[maxn] , vb[maxn];
vector<pll> qu[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	fill(f , f + n , n);
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		p[--a[i]] = i;
	}
	for(ll i = n - 1 ; ~i ; i--){
		ll h = -1;
		while(!v.empty()){
			if(v.back() > a[i]){
				h = p[v.back()];
				break;
			}
			v.pop_back();
		}
		rb[i] = h;
		v.push_back(a[i]);
	}
	v.clear();
	for(ll i = n - 1 ; ~i ; i--){
		ll h = -1;
		while(!v.empty()){
			if(v.back() < a[i]){
				h = p[v.back()];
				break;
			}
			v.pop_back();
		}
		rk[i] = h;
		v.push_back(a[i]);
	}
	v.clear();
	for(ll i = 0 ; i < n ; i++){
		ll h = -1;
		while(!v.empty()){
			if(v.back() > a[i]){
				h = p[v.back()];
				break;
			}
			v.pop_back();
		}
		lb[i] = h;
		v.push_back(a[i]);
	}
	v.clear();
	for(ll i = 0 ; i < n ; i++){
		ll h = -1;
		while(!v.empty()){
			if(v.back() < a[i]){
				h = p[v.back()];
				break;
			}
			v.pop_back();
		}
		lk[i] = h;
		v.push_back(a[i]);
	}
	for(ll i = n - 1 ; ~i ; i--){
		if(rk[i] != -1){
			ll h = rk[i] + 1;
			qu[h].push_back({i , 0});
		}
		if(rb[i] != -1){
			ll h = rb[i] + 1;
			qu[h].push_back({i , 1});
		}
	}
	for(ll i = 0 ; i < n ; i++){
		if(lk[i] != -1){
			vk[lk[i]].push_back(a[i]);
		}
		if(lb[i] != -1){
			vb[lb[i]].push_back(a[i]);
		}
	}
	sk.init(n); sb.init(n);
	for(ll i = n - 1 ; ~i ; i--){
		for(auto j : vb[i]){
			sb.set(j , p[j]);
		}
		for(auto j : vk[i]){
			sk.set(j , p[j]);
		}
		for(auto p : qu[i]){
			ll t = p.second , j = p.first;
			if(!t){
				f[j] = min(f[j] , sb.cal(a[j] , n));
			}
			if(t){
				f[j] = min(f[j] , sk.cal(0 , a[j]));
			}
		}
	}
	ll cur = n , res = 0;
	for(ll i = n - 1 ; ~i ; i--){
		cur = min(cur , f[i]);
		res += cur - i;
	}
	cout<<res<<'\n';
	return 0;
}

// maxne lanati ro check kon