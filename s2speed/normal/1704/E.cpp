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

const ll maxn = 2e5 + 17 , md = 998244353 , inf = 2e16;

vector<ll> adj[maxn] , jda[maxn];
ll w[maxn] , d[maxn] , a[maxn];
vector<ll> t;
priority_queue<pll , vector<pll> , greater<pll>> pq;

void solve(){
	t.clear();
	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		adj[i].clear(); jda[i].clear();
		d[i] = 0;
		cin>>a[i];
	}
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); jda[u].push_back(v);
		d[v]++;
	}
	for(ll i = 0 ; i < n ; i++){
		pq.push({d[i] , i});
	}
	while(!pq.empty()){
		pll p = pq.top(); pq.pop();
		ll v = p.second;
		if(d[v] != p.first) continue;
		for(auto i : jda[v]){
			d[i]--;
			pq.push({d[i] , i});
		}
		t.push_back(v);
	}
	reverse(all(t));
	w[t[n - 1]] = 1;
	for(ll e = n - 2 ; ~e ; e--){
		ll i = t[e] , h = 0;
		for(auto j : adj[i]){
			h += w[j];
		}
		w[i] = h % md;
	}
	ll res = 0 , sum = 0;
	for(ll i = 0 ; i < n ; i++){
		res += w[i] * a[i] % md;
		sum += a[i];
	}
	for(ll k = 0 ; k < n - 1 && sum ; k++){
		res += (a[t[n - 1]] == 0);
		for(ll e = n - 1 ; ~e ; e--){
			ll i = t[e];
			if(!a[i]) continue;
			a[i]--; sum--;
			for(auto j : adj[i]){
				a[j]++; sum++;
			}
		}
	}
	res %= md;
	cout<<res<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}