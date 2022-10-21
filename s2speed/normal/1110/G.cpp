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

const ll maxn = 2e6 + 17 , md = 1e9 + 7 , inf = 2e16;

vector<ll> adj[maxn];
ll d[maxn];

void solve(){
	ll n , o;
	cin>>n; o = n;
	for(ll i = 0 ; i < 4 * n ; i++) adj[i].clear();
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	for(ll i = 0 ; i < n ; i++){
		char c;
		cin>>c;
		if(c == 'N') continue;
		adj[i].push_back(o); adj[o].push_back(i);
		adj[o].push_back(o + 1); adj[o].push_back(o + 2);
		adj[o + 1].push_back(o); adj[o + 2].push_back(o);
		o += 3;
	}
	for(ll i = 0 ; i < o ; i++){
		d[i] = sze(adj[i]);
	}
	ll t = 0;
	for(ll i = 0 ; i < o ; i++){
		if(d[i] >= 4){
			cout<<"White\n";
			return;
		}
		if(d[i] <= 2) continue;
		t++;
		ll cnt = 0;
		for(auto j : adj[i]){
			cnt += (d[j] > 1);
		}
		if(cnt >= 2){
			cout<<"White\n";
			return;
		}
	}
	if(t < 2){
		cout<<"Draw\n";
		return;
	}
	cout<<(((o - 6) & 1) ? "White\n" : "Draw\n");
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}