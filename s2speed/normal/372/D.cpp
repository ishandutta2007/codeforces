#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast,no-stack-protector")

#define all(x) x.begin() , x.end()
#define mp make_pair
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	return ((b == 0) ? a : gcd(b , a % b));
}

const ll MAXN = 1e5 + 15 , MAXD = 1e4 + 15 , md = 1e6 + 3 , inf = 1e18;

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

vector<ll> adj[MAXN] , f;
ll jad[MAXN][20] , st[MAXN] , tme = 0 , dis[MAXN] , dep = 0;

void DFS(ll r , ll par){
	st[r] = tme++;
	f.push_back(r);
	dis[r] = dep++;
	jad[r][0] = par;
	for(ll j = 1 ; j < 20 ; j++){
		if(jad[r][j - 1] == -1) break;
		jad[r][j] = jad[jad[r][j - 1]][j - 1];
	}
	for(auto i : adj[r]){
		if(i == par) continue;
		DFS(i , r);
	}
	dep--;
	return;
}

ll find_jad(ll v , ll h){
	h = dis[v] - h;
	for(ll j = 0 ; j < 20 ; j++){
		if(h & 1){
			v = jad[v][j];
		}
		h >>= 1;
	}
	return v;
}

ll LCA(ll v , ll u){
	if(dis[v] > dis[u]) swap(v , u);
	u = find_jad(u , dis[v]);
	if(v == u) return v;
	for(ll j = 19 ; j >= 0 ; j--){
		if(jad[v][j] != jad[u][j]){
			v = jad[v][j];
			u = jad[u][j];
		}
	}
	return jad[v][0];
}

ll ds(ll v , ll u){
	if(v == -1 || u == -1) return 0;
	ll i = LCA(v , u) , res = dis[v] + dis[u] - 2 * dis[i];
	return res;
}

set<ll> s;

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(jad , -1 , sizeof(jad));
	ll n , k;
	cin>>n>>k;
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	DFS(0 , -1);
	ll sz = 1 , l = 0 , ans = 1 , cur = 1;
	s.insert(st[0]);
	for(ll r = 1 ; r <= n ; r++){
		while(cur > k){
			ll v = -1 , u = -1 , h;
			auto it = s.lower_bound(st[l]);
			if(it != s.begin()){
				it--;
				v = f[*it];
				it++;
			}
			it++;
			if(it != s.end()){
				u = f[*it];
			}
			if(u == -1){
				u = f[*s.begin()];
			}
			if(v == -1){
				it = s.end(); it--;
				v = f[*it];
			}
			h = ds(v , l) + ds(u , l) - ds(v , u); h /= 2;
			cur -= h;
			s.erase(st[l]);
			l++;
		}
		ans = max(r - l , ans);
		if(r < n){
			if(s.size() == 1){
				cur += ds(r , l);
				s.insert(st[r]);
			} else {
				ll v = -1 , u = -1 , h;
				auto it = s.lower_bound(st[r]);
				if(it != s.end()){
					u = f[*it];
				}
				if(it != s.begin()){
					it--;
					v = f[*it];
				}
				if(u == -1){
					u = f[*s.begin()];
				}
				if(v == -1){
					it = s.end(); it--;
					v = f[*it];
				}
				h = ds(v , r) + ds(u , r) - ds(v , u); h /= 2;
				cur += h;
				s.insert(st[r]);
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}

/*

*/