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
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;
 
const ll maxn = 3e5 + 16 , md = 1e9 + 7 , dm = 2000000357 , inf = 2e18;
 
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

ll ds[maxn] , cnt[maxn][3] , ans[maxn] , cur = 0;
vector<pll> v;
ll hs[maxn] , p = 131 , t[maxn] , sf[maxn] , lp[maxn];
ll n;
string s , h;

ll sh(ll l , ll r){
	ll h = hs[r];
	if(l > 0){
		h -= 1ll * hs[l - 1] * t[r - l + 1]; h %= dm; if(h < 0) h += dm;
	}
	return h;
}

ll lcp(ll i , ll j){
	if(i > j) swap(i , j);
	ll l = -1 , r = n - j;
	while(l < r - 1){
		ll m = (r + l) / 2;
		if(sh(i , i + m) == sh(j , j + m)){
			l = m;
		} else {
			r = m;
		}
	}
	return l + 1;
}

bool cmp(ll i , ll j){
	ll l = lcp(i , j);
	if(i + l == n) return true;
	if(j + l == n) return false;
	return s[i + l] < s[j + l];
}

ll dsu(ll v){
	return (ds[v] == v ? v : ds[v] = dsu(ds[v]));
}

void merge(ll v , ll u){
	v = dsu(v); u = dsu(u);
	cur -= 1ll * cnt[v][0] * cnt[v][1] * cnt[v][2] + 1ll * cnt[u][0] * cnt[u][1] * cnt[u][2];
	cnt[v][0] += cnt[u][0]; cnt[v][1] += cnt[u][1]; cnt[v][2] += cnt[u][2];
	cur += 1ll * cnt[v][0] * cnt[v][1] * cnt[v][2]; cur %= md; if(cur < 0) cur += md;
	ds[u] = v;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(cnt , 0 , sizeof(cnt));
	t[0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		t[i] = 1ll * p * t[i - 1] % dm;
	}
	ll a , b;
	cin>>h; s += h; s += '#'; a = sze(s); cin>>h; s += h; s += '#'; b = sze(s); cin>>h; s += h; n = sze(s);
	hs[0] = s[0];
	for(ll i = 1 ; i < n ; i++){
		hs[i] = (1ll * p * hs[i - 1] + s[i]) % dm;
	}
	iota(sf , sf + n , 0);
	sort(sf , sf + n , cmp);
	for(ll i = 0 ; i < n - 1 ; i++){
		lp[i] = lcp(sf[i] , sf[i + 1]);
	}
	iota(ds , ds + n , 0);
	for(ll i = 0 ; i < n ; i++){
		if(sf[i] < a){
			cnt[i][0]++;
			continue;
		}
		if(sf[i] < b){
			cnt[i][1]++;
			continue;
		}
		cnt[i][2]++;
	}
	for(ll i = 0 ; i < n - 1 ; i++){
		v.push_back({lp[i] , i});
	}
	sort(all(v) , greater<pll>()); v.push_back({inf , inf});
	ll x = 0;
	for(ll i = maxn - 1 ; i > 0 ; i--){
		while(v[x].first == i){
			ll j = v[x++].second;
			merge(j , j + 1);
		}
		ans[i] = cur;
	}
	ll lm = min(n - b , min(a , b - a) - 1);
	for(ll i = 1 ; i <= lm ; i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return 0;
}