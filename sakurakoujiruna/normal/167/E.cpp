#include <bits/stdc++.h>
using namespace std;

#define pb push_back
using ll = long long;
ll mod;
ll qpow(ll a, ll b) {
	ll r = 1;
	for(; b; b /= 2) {
		if(b & 1)
			r = r * a % mod;
		a = a * a % mod;
	}
	return r;
}

const int N = 611;

int in[N], out[N], d[N];
vector <int> e[N];

ll dp[N][N];

ll a[N][N];

int main() {
	ios :: sync_with_stdio(0);
	int n, m; cin >> n >> m >> mod;
	while(m --) {
		int u, v; cin >> u >> v;
		out[u] ++; in[v] ++; d[v] ++;
		e[u].pb(v);
	}
	
	queue <int> q;
	vector <int> tp;
	for(int i = 1; i <= n; i ++)
		if(!d[i]) q.push(i);
	while(!q.empty()) {
		int x = q.front(); q.pop();
		tp.pb(x);
		for(int i : e[x]) {
			d[i] --;
			if(!d[i]) q.push(i);
		}
	}

	for(int i : tp) {
		dp[i][i] ++;
		for(int j = 1; j <= n; j ++)
			for(int k : e[i]) {
				dp[j][k] += dp[j][i];
				dp[j][k] %= mod;
			}
	}

	vector <int> vs, ve;
	for(int i = 1; i <= n; i ++) {
		if(!in[i] && out[i]) vs.pb(i);
		if(!out[i] && in[i]) ve.pb(i);
	}
	ll ans = 1;
	for(int i = 1; i <= n; i ++) if(!in[i] && !out[i]) {
		int cs = count_if(vs.begin(), vs.end(), [&](int x){ return x < i; });
		int ce = count_if(ve.begin(), ve.end(), [&](int x){ return x < i; });
		if((cs - ce) & 1) ans = -ans;
	}

	n = vs.size();
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			a[i][j] = dp[vs[i - 1]][ve[j - 1]];

	for(int i = 1; i <= n; i ++) {
		if(!a[i][i]) {
			bool d = 0;
			for(int j = i + 1; j <= n; j ++) if(a[j][i]) {
				for(int k = i; k <= n; k ++)
					swap(a[i][k], a[j][k]);
				ans = -ans; d = 1; break;
			}
			if(!d) { ans = 0; break; }
		}
		for(int j = i + 1; j <= n; j ++) if(a[j][i]) {
			ll t = a[j][i] * qpow(a[i][i], mod - 2) % mod;
			for(int k = i; k <= n; k ++) {
				a[j][k] -= a[i][k] * t % mod;
				a[j][k] %= mod;
			}
		}
		ans = ans * a[i][i] % mod;
	}
	cout << (ans + mod) % mod << '\n';
}