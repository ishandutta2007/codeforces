#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 1e5 + 20;

vector<ll> adj[MAX_N] , dp[MAX_N][20] , p[MAX_N] , ans;
ll a[MAX_N][20] , dis[MAX_N] , d = 0;
bool mark[MAX_N];

vector<ll> merge(vector<ll> &a , vector<ll> &b){
	vector<ll> c;
	bool aa;
	ll as = a.size() , bs = b.size() , x = 0 , y = 0 , top = -1;
	for(int i = 0 ; i < 10 && (x < as || y < bs) ; i++){
		if(x == as){
			aa = false;
		} else if(y == bs){
			aa = true;
		} else {
			if(a[x] < b[y]){
				aa = true;
			} else {
				aa = false;
			}
		}
		if(aa){
			ll cs = c.size();
			if(a[x] == top){
				x++;
				i--;
				continue;
			}
			c.push_back(a[x]);
			top = a[x];
			x++;
		} else {
			if(b[y] == top){
				y++;
				i--;
				continue;
			}
			c.push_back(b[y]);
			top = b[y];
			y++;
		}
	}
	return c;
}

void DFS(ll r){
	dis[r] = d;
	d++;
	mark[r] = true;
	for(int j = 1 ; j < 20 ; j++){
		if(a[r][j - 1] == -1){
			break;
		}
		dp[r][j] = merge(dp[r][j - 1] , dp[a[r][j - 1]][j - 1]);
		a[r][j] = a[a[r][j - 1]][j - 1];
	}
	for(auto u : adj[r]){
		if(!mark[u]){
			a[u][0] = r;
			dp[u][0] = merge(p[r] , p[u]);
			DFS(u);
		}
	}
	d--;	
}

pair<ll , vector<ll> > find_jad(ll r , ll ds){
	vector<ll> y;
	ll t = 1 << 19;
	ds = dis[r] - ds;
	for(int i = 19 ; t >= 1 && ds > 0 ; i-- , t /= 2){
		if(ds >= t){
			y = merge(y , dp[r][i]);
			r = a[r][i];
			ds -= t;
		}
	}
	return {r , y};
}

vector<ll> LCA(ll u , ll v){
	vector<ll> y;
	for(int i = 19 ; i >= 0 && u != v ; i--){
		if(a[u][i] != a[v][i]){
			y = merge(y , dp[u][i]);
			y = merge(y , dp[v][i]);
			u = a[u][i];
			v = a[v][i];
		}
	}
	if(u != v){
		y = merge(y , dp[u][0]);
		y = merge(y , dp[v][0]);
	}
	return y;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , m , q;
	cin>>n>>m>>q;
	for(int i = 1 ; i < n ; i++){
		mark[i] = false;
		ll u , v;
		cin>>u>>v;
		u--;
		v--;
		adj[u].push_back(v); adj[v].push_back(u);
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < 20 ; j++){
			a[i][j] = -1;
		}
	}
	for(int i = 0 ; i < m ; i++){
		ll c;
		cin>>c;
		c--;
		p[c].push_back(i + 1);
	}
	DFS(0);
	while(q--){
		vector<ll> ans , h;
		pair<ll , vector<ll> > e;
		ll u , v , o;
		cin>>u>>v>>o;
		u--;
		v--;
		if(u == v){
			ll ps = p[u].size();
			ps = min(ps , o);
			cout<<ps<<" ";
			for(int b = 0 ; b < ps ; b++){
				cout<<p[u][b]<<" ";
			}
			cout<<"\n";
			continue;
		}
		if(dis[u] > dis[v]){
			e = find_jad(u , dis[v]);
			u = e.first;
			h = e.second;
		} else {
			e = find_jad(v , dis[u]);
			v = e.first;
			h = e.second;
		}
		ans = LCA(u , v);
		ans = merge(ans , h);
		ll as = ans.size();
		as = min(as , o);
		cout<<as<<" ";
		for(int i = 0 ; i < as ; i++){
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
		ans.clear();
		h.clear();
	}
	return 0;
}