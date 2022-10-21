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

vector<ll> adj[maxn];
ll a[maxn] , l[maxn] , r[maxn] , b[maxn] , ans;

void DFS(ll v){
	ll sum = 0;
	for(auto i : adj[v]){
		DFS(i);
		sum += b[i];
	}
	if(sum > r[v]){
		b[v] = r[v];
		return;
	}
	if(sum >= l[v]){
		b[v] = sum;
		return;
	}
	b[v] = r[v];
	ans++;
	return;
}

void solve(){
	ans = 0;
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++) adj[i].clear();
	for(ll i = 1 ; i < n ; i++){
		ll v;
		cin>>v; v--;
		adj[v].push_back(i);
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>l[i]>>r[i];
	}
	DFS(0);
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
} // maxne lanati ro check kon