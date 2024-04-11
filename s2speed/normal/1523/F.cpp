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
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 112 , maxlm = (1 << 14) + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll n , m , lm;
ll x[maxn] , y[maxn] , xq[maxn] , yq[maxn] , dis[maxlm][maxn] , dp[maxlm][maxn] , f[maxlm][maxn] , g[maxlm][maxn] , pt = 0;
vector<pll> t;
priority_queue<plll , vector<plll> , greater<plll>> pq;

void dij(){
	for(ll i = 0 ; i < n ; i++){
		dis[1 << i][0] = 0;
		pq.push({0 , {1 << i , 0}});
	}
	pq.push({2e17 , {maxlm - 1 , maxn - 1}});
	while(!pq.empty()){
		plll q;
		ll v , mask , w;
		while(true){
			q = pq.top();
			v = q.first; mask = q.second.first; w = q.second.second;
			if(t[pt].first > v) break;
			ll i = t[pt].second , ti = t[pt++].first;
			for(ll mask = 0 ; mask < lm ; mask++){
				if(dp[mask][i] < 0) continue;
				for(ll e = pt ; e < m ; e++){
					ll j = t[e].second , tj = t[e].first;
					ll d = abs(xq[i] - xq[j]) + abs(yq[i] - yq[j]);
					if(d <= tj - ti){
						dp[mask][j] = max(dp[mask][j] , dp[mask][i] + 1);
					}
				}
				for(ll j = 0 ; j < n ; j++){
					if(mask & (1 << j)) continue;
					ll d = min(f[mask][j] , abs(x[j] - xq[i]) + abs(y[j] - yq[i])) , h = mask | (1 << j);
					if(dis[h][dp[mask][i]] > ti + d){
						dis[h][dp[mask][i]] = ti + d;
						pq.push({ti + d , {h , dp[mask][i]}});
					}
				}
				if(dis[mask][dp[mask][i]] > ti){
					dis[mask][dp[mask][i]] = ti;
					pq.push({ti , {mask , dp[mask][i]}});
				}
			}
		}
		pq.pop();
		if(v != dis[mask][w]) continue;
		if(v == 2e17) break;
		for(ll j = 0 ; j < n ; j++){
			if(mask & (1 << j)) continue;
			ll h = mask | (1 << j);
			if(dis[h][w] > dis[mask][w] + f[mask][j]){
				dis[h][w] = dis[mask][w] + f[mask][j];
				pq.push({dis[h][w] , {h , w}});
			}
		}
		for(ll e = pt ; e < m ; e++){
			ll j = t[e].second , tj = t[e].first;
			if(v + g[mask][j] <= tj){
				dp[mask][j] = max(dp[mask][j] , w + 1);
			}
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , -31 , sizeof(dp));
	memset(dis , 63 , sizeof(dis));
	dis[maxlm - 1][maxn - 1] = 2e17;
	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		cin>>x[i]>>y[i];
	}
	for(ll i = 0 ; i < m ; i++){
		ll h;
		cin>>xq[i]>>yq[i]>>h;
		t.push_back({h , i});
		dp[0][i] = 1;
	}
	lm = (1 << n);
	for(ll mask = 0 ; mask < lm ; mask++){
		for(ll i = 0 ; i < n ; i++){
			ll res = inf;
			for(ll j = 0 ; j < n ; j++){
				if(!(mask & (1 << j))) continue;
				res = min(res , abs(x[i] - x[j]) + abs(y[i] - y[j]));
			}
			f[mask][i] = res;
		}
		for(ll i = 0 ; i < m ; i++){
			ll res = inf;
			for(ll j = 0 ; j < n ; j++){
				if(!(mask & (1 << j))) continue;
				res = min(res , abs(x[j] - xq[i]) + abs(y[j] - yq[i]));
			}
			g[mask][i] = res;
		}
	}
	sort(all(t)); t.push_back({1e18 , -1});
	dij();
	ll ans = 0;
	for(ll mask = 0 ; mask < lm ; mask++){
		for(ll j = m ; j >= 0 ; j--){
			if(dis[mask][j] < inf){
				ans = max(ans , j);
				break;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}

/*
2 2
100 100
-100 -100
0 0 4
1 2 8
*/