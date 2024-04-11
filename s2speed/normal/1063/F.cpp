#include<bits/stdc++.h>
#include<fstream>
 
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

const ll maxn = 5e5 + 16 , md = 2000000357 , inf = 2e16;

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
		val[x] = max(val[ln] , val[rn]);
		return;
	}

	void set(ll i , ll k){
		set(i , k , 0 , 0 , sz);
		return;
	}

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return 0;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a = cal(l , r , ln , lx , m) , b = cal(l , r , rn , m , rx);
		return max(a , b);
	}

	ll cal(ll l , ll r){
		return cal(l , r , 0 , 0 , sz);
	}

};

ll n;
segtree st;
ll rnk[maxn] , sf[maxn] , t[maxn] , hs[maxn] , lp[maxn] , tv[maxn] , rmq[maxn][20] , dp[maxn];
vector<ll> cnt[maxn];
vector<pll> v;

ll gh(ll l , ll r){
	if(!l) return hs[r - 1];
	ll res = hs[r - 1] - 1ll * tv[r - l] * hs[l - 1]; res %= md; if(res < 0) res += md;
	return res;
}

ll lcp(ll i , ll j){
	if(i > j) swap(i , j);
	ll l = 0 , r = n - j + 1;
	while(l < r - 1){
		ll m = (r + l) >> 1;
		if(gh(i , i + m) == gh(j , j + m)){
			l = m;
		} else {
			r = m;
		}
	}
	return l;
}

ll bu(ll i , ll k){
	for(ll j = 19 ; j >= 0 ; j--){
		ll h = i + (1 << j);
		if(h >= n) continue;
		if(rmq[i][j] >= k) i = h;
	}
	return i;
}

ll bd(ll i , ll k){
	for(ll j = 19 ; j >= 0 ; j--){
		ll h = i - (1 << j);
		if(h < 0) continue;
		if(rmq[h][j] >= k) i = h;
	}
	return i;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll p = 131;
	tv[0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		tv[i] = 1ll * tv[i - 1] * p % md;
	}
	string s;
	cin>>n>>s;
	for(ll i = 0 ; i < n ; i++){
		rnk[i] = s[i] - 'a';
		cnt[rnk[i]].push_back(i);
	}
	ll h = 0;
	for(ll i = 0 ; i < 26 ; i++){
		if(cnt[i].empty()) continue;
		for(auto j : cnt[i]){
			rnk[j] = h;
		}
		cnt[i].clear();
		h++;
	}
	for(ll j = 0 ; j < 20 ; j++){
		ll o = 1 << j , h = -1;
		v.clear();
		if(o >= n) break;
		for(ll i = 0 ; i < n ; i++){
			t[i] = (i + o < n ? rnk[i + o] : -1);
			cnt[t[i] + 1].push_back(i);
		}
		for(ll i = 0 ; i <= n ; i++){
			for(auto j : cnt[i]){
				v.push_back({rnk[j] , j});
			}
			cnt[i].clear();
		}
		for(auto q : v){
			cnt[q.first].push_back(q.second);
		}
		for(ll i = 0 ; i < n ; i++){
			pll p = {inf , inf};
			for(auto j : cnt[i]){
				if(mp(rnk[j] , t[j]) != p){
					p = mp(rnk[j] , t[j]);
					h++;
				}
				rnk[j] = h;
			}
			cnt[i].clear();
		}
	}
	for(ll i = 0 ; i < n ; i++){
		sf[rnk[i]] = i;
	}
	hs[0] = s[0];
	for(ll i = 1 ; i < n ; i++){
		hs[i] = (1ll * p * hs[i - 1] + s[i]) % md;
	}
	for(ll i = 0 ; i < n - 1 ; i++){
		lp[i] = lcp(sf[i] , sf[i + 1]);
	}
	for(ll i = 0 ; i < n - 1 ; i++){
		rmq[i][0] = lp[i];
	}
	for(ll j = 1 ; j < 20 ; j++){
		ll o = 1 << (j - 1);
		if(o >= n - 1) break;
		for(ll i = 0 ; i < n - 1 ; i++){
			if(i + o >= n - 1){
				rmq[i][j] = rmq[i][j - 1];
				continue;
			}
			rmq[i][j] = min(rmq[i][j - 1] , rmq[i + o][j - 1]);
		}
	}
	st.init(n);
	ll x = n - 1 , y = n , ans = 1;
	while(x >= 0){
		if(y - x == 1){
			dp[x] = 1;
			x--;
			continue;
		}
		ll k = y - x , l = bd(rnk[x] , k - 1) , r = bu(rnk[x] , k - 1) + 1 , h;
		h = st.cal(l , r);
		if(h >= k - 1){
			ans = max(ans , k);
			dp[x] = k;
			x--;
			continue;
		}
		l = bd(rnk[x + 1] , k - 1); r = bu(rnk[x + 1] , k - 1) + 1;
		h = st.cal(l , r);
		if(h >= k - 1){
			ans = max(ans , k);
			dp[x] = k;
			x--;
			continue;
		}
		y--;
		st.set(rnk[y] , dp[y]);
	}
	cout<<ans<<'\n';
	return 0;
}

/*
6
abcaba
*/