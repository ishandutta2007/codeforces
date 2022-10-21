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

const ll maxn = 2e5 + 17 , md = 1e9 + 7 , inf = 2e16;

vector<pll> ed;
ll a[maxn] , d[maxn];

void solve(){
	ed.clear();
	ll n , m;
	cin>>n>>m;
	fill(d , d + n , 0);
	for(ll i = 0 ; i < n ; i++) cin>>a[i];
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		d[v] ^= 1; d[u] ^= 1;
		ed.push_back({v , u});
	}
	if(!(m & 1)){
		cout<<"0\n";
		return;
	}
	ll ans = inf;
	for(ll i = 0 ; i < n ; i++){
		if(d[i]){
			ans = min(ans , a[i]);
		}
	}
	for(auto p : ed){
		ll v = p.first , u = p.second;
		if(!d[v] && !d[u]){
			ans = min(ans , a[v] + a[u]);
		}
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