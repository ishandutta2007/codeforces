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

const ll maxn = 4e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll d[maxn];
vector<ll> adj[maxn] , del;
bitset<maxn> dead;
priority_queue<pll , vector<pll> , greater<pll>> pq;

void solve(){
	ll n , k;
	cin>>n>>k;
	for(ll i = 0 ; i < n ; i++){
		adj[i].clear();
		d[i] = 0;
		dead[i] = false;
	}
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
		d[v]++; d[u]++;
	}
	for(ll i = 0 ; i < n ; i++){
		pq.push({d[i] , i});
	}
	for(ll e = 0 ; e < k && !pq.empty() ; e++){
		del.clear();
		while(!pq.empty()){
			pll p = pq.top(); pq.pop();
			ll v = p.second;
			if(dead[v]) continue;
			if(d[v] >= 2) break;
			dead[v] = true;
			del.push_back(v);
		}
		for(auto v : del){
			for(auto i : adj[v]){
				if(dead[i]) continue;
				d[i]--;
				pq.push({d[i] , i});
			}
		}
	}
	ll ans = n;
	for(ll i = 0 ; i < n ; i++){
		ans -= dead[i];
	}
	cout<<ans<<'\n';
	while(!pq.empty()) pq.pop();
	return;	
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T; 
	while(T--) solve();
	return 0;
}