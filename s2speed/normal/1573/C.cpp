#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cout<<"--------------------------------------"<<endl
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

vector<ll> adj[maxn] , jda[maxn] , s;
bitset<maxn> mark;
ll c[maxn] , dp[maxn] , d[maxn];
priority_queue<pll , vector<pll> , greater<pll>> pq;

void solve(){
	ll n;
	cin>>n;
	s.clear();
	for(ll i = 0 ; i < n ; i++){
		adj[i].clear();
		jda[i].clear();
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>d[i];
		for(ll j = 0 ; j < d[i] ; j++){
			ll v;
			cin>>v; v--;
			adj[i].push_back(v);
			jda[v].push_back(i);
		}
		c[i] = -1;
		pq.push({d[i] , i});
	}
	ll cur = 0;
	while(!pq.empty()){
		pll p = pq.top(); pq.pop();
		ll v = p.second;
		if(c[v] != -1) continue;
		if(d[v] != 0){
			cout<<"-1\n";
			return;
		}
		for(auto i : jda[v]){
			d[i]--;
			pq.push({d[i] , i});
		}
		c[v] = cur++;
		s.push_back(v);
	}
	ll ans = 0;
	for(ll e = 0 ; e < n ; e++){
		ll v = s[e];
		dp[v] = 1;
		for(auto i : adj[v]){
			dp[v] = max(dp[v] , dp[i] + (i > v));
		}
		ans = max(ans , dp[v]);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}