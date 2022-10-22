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

const ll maxn = 1e5 + 16 , md = 2000000357 , inf = 2e17;

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

ll n;
vector<plll> cnt[maxn] , v;
ll hs[maxn] , rn[maxn] , sf[maxn] , lp[maxn] , tv[maxn] , pr[maxn] , nt[maxn] , p = 131;
vector<ll> st;

ll get_hash(ll l , ll r){
	if(!l) return hs[r - 1];
	ll res = (hs[r - 1] - 1ll * tv[r - l] * hs[l - 1]) % md; if(res < 0) res += md;
	return res;
}

ll lcp(ll i , ll j){
	if(i > j) swap(i , j);
	ll l = 0 , r = n - j + 1;
	while(l < r - 1){
		ll m = (r + l) >> 1;
		if(get_hash(i , i + m) == get_hash(j , j + m)){
			l = m;
		} else {
			r = m;
		}
	}
	return l;
}

void solve(){
	string s;
	cin>>s; n = sze(s);
	hs[0] = s[0];
	for(ll i = 1 ; i < n ; i++){
		hs[i] = (1ll * hs[i - 1] * p + s[i]) % md;
	}
	for(ll i = 0 ; i < n ; i++){
		rn[i] = s[i] - 'a';
		cnt[rn[i]].push_back({{rn[i] , 0} , i});
	}
	ll h = 1;
	for(ll i = 0 ; i < 26 ; i++){
		if(cnt[i].empty()) continue;
		for(auto q : cnt[i]){
			ll j = q.second;
			rn[j] = h;
		}
		cnt[i].clear();
		h++;
	}
	for(ll j = 0 ; (1 << j) < n ; j++){
		for(ll i = 0 ; i < n ; i++){
			ll o = (i + (1 << j) >= n ? 0 : rn[i + (1 << j)]);
			cnt[o].push_back({{rn[i] , o} , i});
		}
		for(ll i = 0 ; i <= n ; i++){
			for(auto q : cnt[i]){
				v.push_back(q);
			}
			cnt[i].clear();
		}
		for(auto q : v){
			cnt[q.first.first].push_back(q);
		}
		h = 1;
		for(ll i = 0 ; i <= n ; i++){
			if(cnt[i].empty()) continue;
			ll cs = sze(cnt[i]);
			rn[cnt[i][0].second] = h;
			for(ll e = 1 ; e < cs ; e++){
				plll q = cnt[i][e];
				if(q.first.second != cnt[i][e - 1].first.second) h++;
				rn[q.second] = h;
			}
			cnt[i].clear();
			h++;
		}
		v.clear();
	}
	for(ll i = 0 ; i < n ; i++){
		sf[--rn[i]] = i;
	}
	for(ll i = 0 ; i + 1 < n ; i++){
		lp[i] = lcp(sf[i] , sf[i + 1]);
	}
	for(ll i = 0 ; i + 1 < n ; i++){
		ll h = -1;
		while(!st.empty()){
			if(lp[st.back()] <= lp[i]){
				h = st.back();
				break;
			}
			st.pop_back();
		}
		st.push_back(i);
		pr[i] = h;
	}
	st.clear();
	for(ll i = n - 2 ; i >= 0 ; i--){
		ll h = n - 1;
		while(!st.empty()){
			if(lp[st.back()] < lp[i]){
				h = st.back();
				break;
			}
			st.pop_back();
		}
		st.push_back(i);
		nt[i] = h;
	}
	st.clear();
	ll ans = 0;
	for(ll i = 0 ; i < n - 1 ; i++){
		ll res = 0;
		if(pr[i] != -1) res = max(res , lp[pr[i]]);
		if(nt[i] != n - 1) res = max(res , lp[nt[i]]);
		res = lp[i] - res; res *= (nt[i] - pr[i]) * (nt[i] - pr[i]);
		ans += res;
	}
	for(ll i = 0 ; i < n ; i++){
		ll h = 0;
		if(i) h = max(h , lp[i - 1]);
		if(i < n - 1) h = max(h , lp[i]);
		ans += n - sf[i] - h;
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	tv[0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		tv[i] = 1ll * p * tv[i - 1] % md;
	}
	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}