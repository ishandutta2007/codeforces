#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll , ll> pll;

const ll MAX_N = 1.5e5 + 20 , md = 998244353;

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
			res %= md;
		}
		n *= n;
		n %= md;
		k /= 2;
	}
	return res;
}

vector<ll> adj[MAX_N];
ll z[MAX_N] , jad[MAX_N][20] , s[MAX_N] , f[MAX_N] , t = 0 , b[MAX_N] , depth = 0 , o[MAX_N] , c[MAX_N] , dis[MAX_N] , n;
vector<pll> k;

void DFS(ll r){
	s[r] = t++;
	dis[r] = depth++;
	for(int j = 1 ; j < 20 ; j++){
		if(jad[r][j - 1] <= -1){
			break;
		}
		jad[r][j] = jad[jad[r][j - 1]][j - 1];
	}
	for(auto i : adj[r]){
		if(jad[i][0] == -1){
			jad[i][0] = r;
			DFS(i);
		}
	}
	z[r] = 1;
	for(auto i : adj[r]){
		if(jad[i][0] == r){
			z[r] += z[i];
		}
	}
	f[r] = t;
	depth--;
}

ll find_jad(ll v , ll d){
	d = dis[v] - d;
	for(int j = 0 ; d > 0 ; j++ , d /= 2){
		if(d & 1){
			v = jad[v][j];
		}
	}
	return v;
}

void update(){
	k.clear();
	for(int i = 0 ; i < n ; i++){
		if(!b[i]){
			continue;
		}
		c[0] += 1ll * b[i] * z[i];
		c[s[i]] -= 1ll * b[i] * z[i];
		c[f[i]] += 1ll * b[i] * z[i];
		c[n] -= 1ll * b[i] * z[i];
		c[s[i]] += 1ll * b[i] * n;
		c[s[i] + 1] -= 1ll * b[i] * n;
		for(auto u : adj[i]){
			if(dis[u] == dis[i] + 1){
				c[s[u]] += 1ll * b[i] * (n - z[u]);
				c[f[u]] -= 1ll * b[i] * (n - z[u]);
			}
		}
	}
	for(int i = 1 ; i < n ; i++){
		c[i] += c[i - 1];
		o[i] += c[i];
	}
	o[0] += c[0];
	for(int i = 0 ; i < n ; i++){
		b[i] = 0;
		c[i] = 0;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll q , ma , dec;
	cin>>n>>q; ma = tav(n , md - 2); dec = sqrt(n / log2(n)); dec = max(1ll , dec); dec *= 2;
	for(int i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[u].push_back(v); adj[v].push_back(u);
	}
	for(int i = 0 ; i < n ; i++){
		b[i] = 0;
		o[i] = 0;
		for(int j = 0 ; j < 20 ; j++){
			jad[i][j] = -1;
		}
	}
	jad[0][0] = -2;
	DFS(0);
	for(int p = 0 ; p < q ; p++){
		ll op;
		cin>>op; op--;
		if(!op){
			ll v , d;
			cin>>v>>d; v--;
			k.push_back( {v , d} );
			b[v] += d;
		} else {
			ll v;
			cin>>v; v--;
			ll ans = o[s[v]];
			for(auto qu : k){
				ll u = qu.first , d = qu.second;
				if(s[v] < s[u] || s[v] >= f[u]){
					ans += 1ll * z[u] * d;
				} else if(v == u){
					ans += 1ll * n * d;
				} else {
					ll h = find_jad(v , dis[u] + 1);
					ans += 1ll * (n - z[h]) * d;
				}
			}
			ans %= md;
			ans *= ma;
			ans %= md;
			cout<<ans<<'\n';
		}
		if(p % dec == dec - 1){
			update();
		}
	}
	return 0;
}