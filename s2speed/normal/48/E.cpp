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

const ll maxn = 5e4 + 17 , md = 1e9 + 7 , inf = 2e16;

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

ll an[maxn] , bn[maxn] , am[maxn] , bm[maxn] , dis[maxn] , d[maxn] , dp[maxn];
vector<ll> adj[maxn] , bfs , rs , tp;
priority_queue<pll , vector<pll> , greater<pll>> pq;

void BFS(ll r){
	bfs.push_back(r);
	dis[r] = 0;
	ll x = 0;
	while(x < sze(bfs)){
		ll v = bfs[x++];
		for(auto i : adj[v]){
			if(dis[i] > dis[v] + 1){
				dis[i] = dis[v] + 1;
				bfs.push_back(i);
			}
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dis , 63 , sizeof(dis));
	memset(d , 0 , sizeof(d));
	memset(dp , 0 , sizeof(dp));
	ll a , b , z , n , m;
	cin>>a>>b>>z; z++;
	cin>>n;
	for(ll i = 1 ; i <= n ; i++){
		cin>>an[i]>>bn[i];
	}
	cin>>m;
	for(ll i = 1 ; i <= m ; i++){
		cin>>am[i]>>bm[i];
	}
	ll f = z * z;
	for(ll i = 0 ; i < z ; i++){
		for(ll j = 0 ; j + i < z ; j++){
			ll ln = min(n , i) , lm = min(m , j) , v = i * z + j;
			rs.push_back(v);
			for(ll k = 1 ; k <= ln ; k++){
				ll ha = i - k + an[k] , hb = j + bn[k];
				if(ha + hb >= z){
					adj[v].push_back(f);
				} else {
					ll u = ha * z + hb;
					adj[v].push_back(u);
				}
			}
			for(ll k = 1 ; k <= lm ; k++){
				ll ha = i + am[k] , hb = j - k + bm[k];
				if(ha + hb >= z){
					adj[v].push_back(f);
				} else {
					ll u = ha * z + hb;
					adj[v].push_back(u);
				}
			}
		}
	}
	rs.push_back(f);
	BFS(a * z + b);
	if(dis[0] < inf){
		cout<<"Ivan\n"<<dis[0]<<'\n';
		return 0;
	}
	for(auto v : rs){
		if(dis[v] >= inf) continue;
		for(auto i : adj[v]) d[i]++;
	}
	for(auto v : rs){
		if(dis[v] >= inf) continue;
		pq.push({d[v] , v});
	}
	bool dr = false;
	while(!pq.empty()){
		pll p = pq.top(); pq.pop();
		ll v = p.second;
		if(d[v] != p.first) continue;
		if(d[v] > 0){
			dr = true;
			break;
		}
		for(auto i : adj[v]){
			d[i]--;
			pq.push({d[i] , i});
			dp[i] = max(dp[i] , dp[v] + 1);
		}
	}
	if(dr){
		cout<<"Draw\n";
		return 0;
	}
	cout<<"Zmey\n";
	cout<<dp[f]<<'\n';
	return 0;
}