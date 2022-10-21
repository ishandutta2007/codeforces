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

const ll maxn = 3e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

vector<ll> adj[maxn];
ll z[maxn] , hc[maxn][20];

void pDFS(ll r){
	z[r] = 1;
	ll m = -1 , ind = -1;
	for(auto i : adj[r]){
		pDFS(i);
		z[r] += z[i];
		if(z[i] > m){
			m = z[i];
			ind = i;
		}
	}
	hc[r][0] = ind;
	for(ll j = 1 ; j < 20 ; j++){
		if(hc[r][j - 1] == -1) break;
		hc[r][j] = hc[hc[r][j - 1]][j - 1];
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(hc , -1 , sizeof(hc));
	ll n , q;
	cin>>n>>q;
	for(ll i = 1 ; i < n ; i++){
		ll pr;
		cin>>pr; pr--;
		adj[pr].push_back(i);
	}
	pDFS(0);
	for(ll e = 0 ; e < q ; e++){
		ll v , h;
		cin>>v; v--; h = z[v] >> 1;
		for(ll j = 19 ; ~j ; j--){
			if(hc[v][j] == -1) continue;
			if(z[hc[v][j]] > h){
				v = hc[v][j];
			}
		}
		cout<<v + 1<<'\n';
	}
	return 0;
}