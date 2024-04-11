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

const ll maxn = 4e5 + 17 , md = 1e9 + 7 , inf = 2e16;

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

ll n , q;
string s;
ll rnk[maxn] , hnk[maxn] , sf[maxn] , lc[maxn] , lk[maxn];
vector<ll> cnt[maxn] , v;

struct segtree {

	ll sz = 1;
	vector<ll> val;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , inf);
		return;
	}

	void build(ll x , ll lx , ll rx){
		if(rx - lx == 1){
			if(lx < n - 1) val[x] = lc[lx];
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		build(ln , lx , m); build(rn , m , rx);
		val[x] = min(val[ln] , val[rn]);
		return;
	}

	void build(){
		build(0 , 0 , sz);
		return;
	}

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return inf;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a = cal(l , r , ln , lx , m) , b = cal(l , r , rn , m , rx);
		return min(a , b);
	}

	ll cal(ll l , ll r){
		if(l == r) return n - sf[l];
		return cal(l , r , 0 , 0 , sz);
	}

};

segtree st;
vector<pll> u , t;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>q>>s;
	if(n == 1){
		for(ll i = 0 ; i < q ; i++){
			cout<<"1\n";
		}
		return 0;
	}
	ll lm = max(130ll , n + 1);
	for(ll i = 0 ; i < n ; i++){
		rnk[i] = s[i];
	}
	for(ll o = 1 ; o < n ; o <<= 1){
		for(ll i = 0 ; i < n - o ; i++){
			hnk[i] = rnk[i + o];
		}
		for(ll i = n - o ; i < n ; i++) hnk[i] = 0;
		for(ll i = 0 ; i < lm ; i++) cnt[i].clear();
		v.clear();
		for(ll i = 0 ; i < n ; i++){
			cnt[hnk[i]].push_back(i);
		}
		for(ll i = 0 ; i < lm ; i++){
			for(auto j : cnt[i]){
				v.push_back(j);
			}
		}
		for(ll i = 0 ; i < lm ; i++) cnt[i].clear();
		for(auto i : v){
			cnt[rnk[i]].push_back(i);
		}
		ll r = 0;
		for(ll i = 0 ; i < lm ; i++){
			ll pr = -1;
			for(auto j : cnt[i]){
				if(hnk[j] != pr){
					r++;
					pr = hnk[j];
				}
				rnk[j] = r;
			}
		}
	}
	for(ll i = 0 ; i < n ; i++){
		sf[rnk[i] - 1] = i;
	}
	ll pr = 0; s += '$';
	for(ll i = 0 ; i < n ; i++){
		if(rnk[i] == 1){
			pr = 0;
			continue;
		}
		ll x = i + pr , y = sf[rnk[i] - 2] + pr;
		while(true){
			if(s[x] != s[y]) break;
			x++; y++;
		}
		pr = max(0ll , x - i - 1);
		lc[rnk[i] - 2] = x - i;
	}
//	cout<<s<<'\n';
//	for(ll i = 0 ; i < n ; i++){
//		cout<<sf[i]<<' ';
//	}
//	cout<<'\n';
//	for(ll i = 0 ; i < n ; i++){
//		cout<<lc[i]<<' ';
//	}
//	cout<<'\n';
	st.init(n);
	st.build();
	for(ll e = 0 ; e < q ; e++){
		u.clear();
		ll k0 , k1;
		cin>>k0>>k1;
		for(ll i = 0 ; i < k0 ; i++){
			ll h;
			cin>>h;
			u.push_back({rnk[h - 1] - 1 , 0});
		}
		for(ll i = 0 ; i < k1 ; i++){
			ll h;
			cin>>h;
			u.push_back({rnk[h - 1] - 1 , 1});
		}
		sort(all(u));
		ll cnt = 0 , res = 0 , val = 0 , k = k0 + k1;
		for(ll i = 0 ; i < k - 1 ; i++){
			lk[i] = st.cal(u[i].first , u[i + 1].first);
		}
		t.clear();
		t.push_back({-1 , 0});
		for(ll i = 0 ; ; i++){
			res += val * (u[i].second ^ 1);
			if(i == k - 1) break;
			ll h = 0 , pr = cnt , pv;
			while(!t.empty()){
				if(t.back().first < lk[i]){
					h = t.back().second;
					break;
				}
				pr = t.back().second;
				pv = t.back().first;
				t.pop_back();
				val -= (pr - t.back().second) * pv;
			}
			cnt += u[i].second;
			val += (cnt - h) * lk[i];
			t.push_back({lk[i] , cnt});
		}
		t.clear(); cnt = 0; val = 0;
		t.push_back({-1 , 0});
		for(ll i = 0 ; ; i++){
			res += val * u[i].second;
			if(i == k - 1) break;
			ll h = 0 , pr = cnt , pv;
			while(!t.empty()){
				if(t.back().first < lk[i]){
					h = t.back().second;
					break;
				}
				pr = t.back().second;
				pv = t.back().first;
				t.pop_back();
				val -= (pr - t.back().second) * pv;
			}
			cnt += u[i].second ^ 1;
			val += (cnt - h) * lk[i];
			t.push_back({lk[i] , cnt});
		}
		cout<<res<<'\n';
	}
	return 0;
}

/*
7 1
abacaba
2 2
1 2
1 2
*/