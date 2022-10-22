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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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
	vector<ll> val;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , 0);
		return;
	}

	void add(ll i , ll k , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x] += k;
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(i < m){
			add(i , k , ln , lx , m);
		} else {
			add(i , k , rn , m , rx);
		}
		val[x] = max(val[ln] , val[rn]);
		return;
	}

	void add(ll i , ll k){
		add(i , k , 0 , 0 , sz);
		return;
	}

	ll cal(ll l , ll r , ll k , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return -1;
		if(val[x] < k) return -1;
		if(rx - lx == 1) return lx;
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a = cal(l , r , k , ln , lx , m);
		if(a != -1) return a;
		a = cal(l , r , k , rn , m , rx);
		return a;
	}

	ll cal(ll l , ll r , ll k){
		return cal(l , r , k , 0 , 0 , sz);
	}

};

segtree st;
ll x[maxn] , t[maxn] , d[maxn] , cnt[maxn];
vector<pll> v , er;
multiset<pll> s;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	ll n , q;
	cin>>n>>q;
	for(ll i = 0 ; i < n ; i++){
		cin>>x[i]>>t[i]; d[i] = x[i] + t[i];
		v.push_back({x[i] , i});
	}
	sort(all(v));
	st.init(n);
	for(ll i = 0 ; i < n ; i++){
		st.add(i , d[v[i].second]);
	}
	for(ll e = 0 ; e < q ; e++){
		ll a , b , i , h , j;
		cin>>a>>b;
		i = upper_bound(all(v) , mp(a , inf)) - v.begin();
		if(!i) continue;
		h = st.cal(0 , i , a);
		if(h == -1){
			s.insert({a , b});
			continue;
		}
		j = v[h].second;
		st.add(h , b);
		d[j] += b;
		cnt[j]++;
		auto it = s.upper_bound({x[j] , -1}) , et = s.end();
		while(it != et){
			pll p = *it;
			if(p.first > d[j]) break;
			st.add(h , p.second);
			d[j] += p.second;
			cnt[j]++;
			er.push_back(p);
			it++;
		}
		for(auto p : er){
			s.erase(p);
		}
		er.clear();
	}
	for(ll i = 0 ; i < n ; i++){
		cout<<cnt[i]<<' '<<d[i] - x[i]<<'\n';
	}
	return 0;
}