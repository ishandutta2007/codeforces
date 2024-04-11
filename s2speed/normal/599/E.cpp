#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 15 , md = 2000000357 , inf = 2e10;

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

ll lca[maxn][maxn] , dp[1 << 13][maxn];
bitset<13> h , adj[13];
vector<ll> a , b;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(lca , -1 , sizeof(lca));
	memset(dp , 0 , sizeof(dp));
	ll n , m , q;
	cin>>n>>m>>q;
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v][u] = adj[u][v] = true;
	}
	for(ll i = 0 ; i < n ; i++){
		lca[i][i] = i;
	}
	for(ll i = 0 ; i < q ; i++){
		ll v , u , w;
		cin>>v>>u>>w; v--; u--; w--;
		if(lca[v][u] != -1 && lca[v][u] != w){
			cout<<"0\n";
			return 0;
		}
		lca[v][u] = lca[u][v] = w;
	}
	int lm = 1 << n;
	for(ll mask = 1 ; mask < lm ; mask++){
		if(__builtin_popcount(mask) == 1){
			for(ll j = 0 ; j < n ; j++){
				if(mask == (1 << j)) dp[mask][j] = 1;
			}
			continue;
		}
		h = mask;
		for(ll r = 0 ; r < n ; r++){
			if(!h[r]) continue;
			ll t = -1;
			for(ll i = 0 ; i < n ; i++){
				if(i == r) continue;
				if(h[i]){
					t = i;
					break;
				}
			}
			ll v = mask - (1 << r) - (1 << t);
			for(ll smask = v ; smask >= 0 ; smask = (smask - 1) & v){
				ll o = smask + (1 << t) , e = mask ^ o , cnt = 0 , y = -1;
				a.clear();
				for(ll j = 0 ; j < n ; j++){
					if(o & (1 << j)){
						a.push_back(j);
						cnt += adj[j][r];
						if(adj[j][r]) y = j;
					}
				}
				b.clear();
				for(ll j = 0 ; j < n ; j++){
					if(e & (1 << j)) b.push_back(j);
				}
				bool ch = true;
				for(auto i : a){
					for(auto j : b){
						ch &= (lca[i][j] == -1) | (lca[i][j] == r);
						if(j == r) continue;
						ch &= !(adj[i][j]);
					}
				}
				if(!ch || cnt > 1){
					if(!smask) break;
					continue;
				}
				if(cnt == 1){
					dp[mask][r] += 1ll * dp[o][y] * dp[e][r];
					if(!smask) break;
					continue;
				}
				for(ll q = 0 ; q < n ; q++){
					if(!(o & (1 << q))) continue;
					dp[mask][r] += 1ll * dp[o][q] * dp[e][r];
				}
				if(!smask) break;
			}
		}
	}
	cout<<dp[lm - 1][0]<<'\n';
	return 0;
}