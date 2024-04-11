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

const ll maxn = 1e5 + 16 , md = 1e9 + 7;
ll inf;

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

ll ds[maxn] , dsz[maxn] , cnt[maxn] , t[6] , dp[maxn] , pd[maxn];
vector<pll> v;

ll dsu(ll v){
	return (ds[v] == v ? v : ds[v] = dsu(ds[v]));
}

void merge(ll v , ll u){
	v = dsu(v); u = dsu(u);
	if(v == u) return;
	if(dsz[v] < dsz[u]) swap(v , u);
	dsz[v] += dsz[u]; dsz[u] = 0;
	ds[u] = v;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	t[0] = 1;
	for(ll i = 1 ; i < 6 ; i++){
		t[i] = t[i - 1] * 10;
	}
	ll n , m;
	cin>>n>>m;
	memset(pd , 63 , sizeof(pd));
	memset(dp , 63 , sizeof(dp));
	inf = dp[0];
	memset(cnt , 0 , sizeof(cnt));
	fill(dsz , dsz + n , 1);
	iota(ds , ds + n , 0);
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		merge(v , u);
	}
	for(ll i = 0 ; i < n ; i++){
		cnt[dsz[i]]++;
	}
	for(ll i = 1 ; i <= n ; i++){
		if(!cnt[i]) continue;
		ll o = 1;
		while(o < cnt[i]){
			v.push_back({o * i , o});
			cnt[i] -= o;
			o <<= 1;
		}
		v.push_back({cnt[i] * i , cnt[i]});
	}
	pd[0] = 0;
	for(auto p : v){
		ll j = p.first , w = p.second;
		for(ll i = 0 ; i <= n ; i++){
			dp[i] = min(pd[i] , (i < j ? inf : pd[i - j] + w));
		}
		memcpy(pd , dp , sizeof(dp));
	}
	ll ans = inf;
	for(ll i = 1 ; i < 6 ; i++){
		ll lm = (1 << i) , q = 0;
		for(ll e = 0 ; e < i ; e++){
			q += 4 * t[e];
		}
		if(q > n) break;
		for(ll k = 0 ; k < lm ; k++){
			ll h = q;
			for(ll j = 0 ; j < i ; j++){
				if(k & (1 << j)) h += 3 * t[j];
			}
			if(h > n) break;
			ans = min(ans , dp[h]);
		}
	}
	cout<<(ans == inf ? 0 : ans) - 1<<'\n';
	return 0;
}