#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 0 + 15 , MAXM = 2e3 + 15 , MAXB = (1 << 12) + 15 , md = 1e9 + 7 , inf = 1e15;

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k /= 2;
	}
	return res;
}

ll dp[MAXN][MAXB] , ans[MAXN][MAXB] , a[MAXN][MAXN] , g[MAXN][MAXM] , mx[MAXM];
vector<pll> v;
vector<ll> u;

void solve(){
	v.clear();
	memset(ans , 0 , sizeof(ans));
	memset(dp , 0 , sizeof(dp));
	memset(mx , 0 , sizeof(mx));
	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			cin>>g[i][j];
			mx[j] = max(mx[j] , g[i][j]);
		}
	}
	for(ll i = 0 ; i < m ; i++){
		v.push_back({mx[i] , i});
	}
	sort(all(v) , greater<pll>());
	m = min(n , m);
	for(ll e = 0 ; e < m ; e++){
		ll j = v[e].second;
		for(ll i = 0 ; i < n ; i++){
			a[i][e] = g[i][j];
		}
	}
	ll lm = (1 << n) - 1;
	for(ll j = 0 ; j < m ; j++){
		for(ll mask = 0 ; mask <= lm ; mask++){
			u.clear();
			ll o = 1;
			for(ll q = 0 ; q < n ; q++){
				if(mask & o){
					u.push_back(q);
				}
				o <<= 1;
			}
			for(ll i = 0 ; i < n ; i++){
				ll h = 0;
				for(auto t : u){
					h += a[(t + i) % n][j];
				}
				dp[j][mask] = max(dp[j][mask] , h);
			}
		}
	}
	for(ll mask = 0 ; mask <= lm ; mask++){
		ans[0][mask] = dp[0][mask];
	}
	for(ll j = 1 ; j < m ; j++){
		for(ll mask = 0 ; mask <= lm ; mask++){
			for(ll sub = mask ; sub >= 0 ; sub = (sub - 1) & mask){
				ll mot = mask ^ sub , h;
				h = ans[j - 1][mot] + dp[j][sub];
				ans[j][mask] = max(ans[j][mask] , h);
				if(!sub) break;
			}
		}
	}
	cout<<ans[m - 1][lm]<<'\n';
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

/*

*/