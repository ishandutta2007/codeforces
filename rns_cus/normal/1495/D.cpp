#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << H << ' ';
	debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 0
#endif

#define N 404

int n, m, d[N][N], cnt[N][N];
const int inf = 1e9;
int dep[N], id[N];
vector <int> vec[N], adj[N];
const int mod = 998244353;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) for (int j = 1; j <= n; j ++) if (i != j) d[i][j] = inf;
    while (m --) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
		d[u][v] = d[v][u] = 1;
    }
    for (int k = 1; k <= n; k ++) for (int i = 1; i <= n; i ++) for (int j = 1; j <= n; j ++)
		d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
	for (int i = 1; i <= n; puts(""), i ++) for (int j = 1; j <= n; j ++) {
		for (int k = 0; k <= n; k ++) vec[k].clear();
		int D = d[i][j];
		bool fg = true;
		for (int k = 1; k <= n; k ++) {
			int d1 = d[i][k], d2 = d[j][k];
			int c = d1 + d2 - D;
			if (c & 1) {
				fg = false; break;
			}
			c >>= 1;
			dep[k] = c; id[k] = d1 - c;
			vec[d1-c].push_back(k);
		}
		int ans = 1;
		if (!fg) ans = 0;
		else {
			for (int k = 0; k <= D; k ++) {
				sort(vec[k].begin(), vec[k].end(), [&](int i, int j) {return dep[i] > dep[j];});
				int c = 0;
				for (auto u : vec[k]) {
					if (dep[u] == 0) {
						c ++; continue;
					}
					int cnt = 0;
					for (auto v : adj[u]) if (id[v] == id[u] && dep[v] == dep[u] - 1) cnt ++;
					ans = 1ll * ans * cnt % mod;
				}
				if (c != 1) {
					ans = 0; break;
				}
			}
		}
		printf("%d ", ans);
	}

    return 0;
}