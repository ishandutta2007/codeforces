#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cout<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 3e6 + 16 , md = 1e9 + 7 , inf = 2e16;

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

struct segtree {

	ll sz = 1;
	vector<ll> val , cnt;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , 0);
		cnt.assign(sz << 1 , 0);
		return;
	}
	
	void set(ll i , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x] = i;
			cnt[x] = 1;
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(i < m){
			set(i , ln , lx , m);
		} else {
			set(i , rn , m , rx);
		}
		val[x] = val[ln] + val[rn];
		cnt[x] = cnt[ln] + cnt[rn];
		return;
	}

	void set(ll i){
		set(i , 0 , 0 , sz);
		return;
	}

	pll cal(ll k , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			return {val[x] , lx};
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(cnt[ln] >= k){
			return cal(k , ln , lx , m);
		}
		pll p = cal(k - cnt[ln] , rn , m , rx);
		p.first += val[ln];
		return p;
	}	

	pll cal(ll k){
		return cal(k , 0 , 0 , sz);
	}

	ll sum(ll l , ll r , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return 0;
		if(rx <= r && lx >= l) return cnt[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a = sum(l , r , ln , lx , m) , b = sum(l , r , rn , m , rx);
		return a + b;
	}

	ll sum(ll l , ll r){
		return sum(l , r , 0 , 0 , sz);
	}

};

segtree st;
ll a[maxn] , p[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n = 0 , sum = 0 , inv = 0;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
		p[a[i]] = i;
	}
	st.init(n);
	for(ll i = 0 ; i < n ; i++){
		inv += st.sum(p[i] , n);
		sum += p[i];
		st.set(p[i]);
		ll t = (i + 2) >> 1 , q = i + 1 - t;
		pll p = st.cal(t);
		ll h = p.first , o , ans = inv , j = p.second;
		ans -= h;
		o = 1ll * j * (j + 1) / 2 - 1ll * (j - t) * (j - t + 1) / 2;
		ans += o;
		h = sum - h;
		ans += h;
		o = 1ll * (j + q) * (j + q + 1) / 2 - 1ll * j * (j + 1) / 2;
		ans -= o;
		cout<<ans<<' ';
	}
	cout<<'\n';
	return 0;
}