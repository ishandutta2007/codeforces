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

vector<ll> adj[maxn];
ll a[maxn] , z[maxn] , o , cnt;

void zDFS(ll r , ll par){
	z[r] = a[r];
	for(auto i : adj[r]){
		if(i == par) continue;
		zDFS(i , r);
		z[r] ^= z[i];
	}
	if(z[r] == o && r){
		z[r] = 0;
		cnt++;
	}
	return;
}

void solve(){
	ll n , k;
	cin>>n>>k; o = 0; cnt = 0;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; o ^= a[i];
		adj[i].clear();
	}
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	if(o == 0){
		cout<<"YES\n";
		return;
	}
	if(k == 2){
		cout<<"NO\n";
		return;
	}
	zDFS(0 , -1);
	cout<<(cnt >= 2 ? "YES" : "NO")<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}