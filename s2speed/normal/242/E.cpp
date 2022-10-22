#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;

struct segtree{

	ll size = 0;
	vector<ll> val , laz;
	
	void init(ll n){
		size = 1;
		while(size < n){
			size *= 2;
		}
		laz.assign(2 * size , 0);
		val.assign(2 * size , 0);
		return;
	}

	void build(vector<ll> &a , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			if(lx < a.size()){
				val[x] = a[lx];
			}
			return;
		}
		ll m = (rx + lx) / 2;
		build(a , 2 * x + 1 , lx , m);
		build(a , 2 * x + 2 , m , rx);
		val[x] = val[2 * x + 1] + val[2 * x + 2];
		return;
	}

	void build(vector<ll> &a){
		build(a , 0 , 0 , size);
		return;
	}

	void swap(ll l , ll r , ll x , ll lx , ll rx){
		if(laz[x]){
			val[x] = rx - lx - val[x];
			if(rx - lx > 1){
				laz[2 * x + 1] ^= 1;
				laz[2 * x + 2] ^= 1;
			}
			laz[x] = 0;
		}
		if(rx <= r && lx >= l){
			val[x] = rx - lx - val[x];
			if(rx - lx > 1){
				laz[2 * x + 1] ^= 1;
				laz[2 * x + 2] ^= 1;
			}
			return;
		}
		if(rx <= l || lx >= r){
			return;
		}
		ll m = (rx + lx) / 2;
		swap(l , r , 2 * x + 1 , lx , m); swap(l , r , 2 * x + 2 , m , rx);
		val[x] = val[2 * x + 1] + val[2 * x + 2];
		return;
	}

	void swap(ll l , ll r){
		swap(l , r , 0 , 0 , size);
		return;
	}

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		if(laz[x]){
			val[x] = rx - lx - val[x];
			if(rx - lx > 1){
				laz[2 * x + 1] ^= 1;
				laz[2 * x + 2] ^= 1;
			}
			laz[x] = 0;
		}
		if(lx >= l && rx <= r){
			return val[x];
		}
		if(lx >= r || rx <= l){
			return 0;
		}
		ll m = (rx + lx) / 2 , a = cal(l , r , 2 * x + 1 , lx , m) , b = cal(l , r , 2 * x + 2 , m , rx);
		return a + b;
	}

	ll cal(ll l , ll r){
		return cal(l , r , 0 , 0 , size);
	}

};

const int MAX_N = 1e5 + 20;

segtree st[20];
vector<ll> v[20];
ll p[20];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n;
	cin>>n;
	p[0] = 1;
	for(int j = 1 ; j < 20 ; j++){
		p[j] = p[j - 1] << 1;
	}
	for(int i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		for(int j = 0 ; j < 20 ; j++){
			v[j].push_back(bool(h & p[j]));
		}
	}
	for(int j = 0 ; j < 20 ; j++){
		st[j].init(n);
		st[j].build(v[j]);
	}
	ll q;
	cin>>q;
	while(q--){
		ll op;
		cin>>op; op--;
		if(op){
			ll l , r , x;
			cin>>l>>r>>x; l--;
			for(int j = 0 ; j < 20 ; j++){
				if(x & p[j]){
					st[j].swap(l , r);
				}
			}
		} else {
			ll l , r , ans = 0 , h;
			cin>>l>>r; l--;
			for(int j = 0 ; j < 20 ; j++){
				h = st[j].cal(l , r);
				ans += 1ll * h * p[j];
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}