// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 105;

int n, inf[N][N][N];


// 
struct DSU{
	int f[N], sz[N];
	void init(int n) { for (int i = 1; i <= n; i++) f[i] = i, sz[i] = 1; }
	int inline find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
	void inline merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return;
		if (sz[x] > sz[y]) swap(x, y);
		sz[y] += sz[x], f[x] = y;
	}
	int df() {
		int ct = 0;
		for (int i = 1; i <= n; i++) if (find(i) == i) ct++;
		return ct;
	}
} to[N];

char s[N];

vector<PII> e;
vector<int> g[N];

void inline add(int x, int y) {
	e.pb(mp(x, y));
	g[x].pb(y), g[y].pb(x);
}

int mx[N], dep[N];

vector<int> t[N];

int dis[N];

bool vis[N];

bool ok = 1;

void dfs(int u, int fa) {
	vis[u] = 1;
	for (int v: g[u]) {
		if (v == fa) continue;
		dis[v] = dis[u] + 1;
		if (vis[v]) {
			ok = 0;
			return;
		}
		dfs(v, u);
	}
}

bool inline chk() {
	ok = 1;
	for (int i = 1; i <= n; i++) {
		dis[i] = 0;
		for (int j = 1; j <= n; j++) vis[j] = 0;
		dfs(i, 0);
		if (!ok) return 0;
		for (int x = 1; x <= n; x++) {
			for (int y = x + 1; y <= n; y++) {
				if ((dis[x] == dis[y] ? 1 : 0) != inf[i][x][y]) return 0;
			}
		}
	}
	return 1;
}

void inline no() {
	puts("No");
}

void inline solve() {
	for (int i = 1; i <= n; i++) mx[i] = dep[i] = dis[i] = 0, g[i].clear(), t[i].clear();
	e.clear();
	int z = 0, mn = 2e9;
	for (int i = 1; i <= n; i++) {
		mx[i] = to[i].df();
		chkMax(z, mx[i] - 1);
		chkMin(mn, mx[i]);
	}
	vector<int> w;
	for (int i = 1; i <= n; i++) if (mx[i] == mn) w.pb(i);
	if (w.size() > 2) {
		no();
		 return;
	}
	for (int i = 1; i <= n; i++) {
		if (w.size() == 1) {
			if (z % 2 != 0) {
				no();
		 		return;
			}
			dep[i] = mx[i] - 1 - (z / 2);
		} else {
			if (z % 2 == 0) {
				no();
				return;
			}
			dep[i] = mx[i] - 1 - (z / 2);
		}
		if (dep[i] < 0) {
			no();
			return;
		}
		t[dep[i]].pb(i);
	}
	if (w.size() == 2) {
		add(w[0], w[1]);
	} else {
		for (int v: t[1]) add(w[0], v);
	}
	// cout << z << "??" << w[0] << " " << w[1] << " " << w.size() << endl;
	// for (int i = 1; i <= n; i++) cout << dep[i] << endl;
	for (int i = 1; i <= n; i++) {
		if (!t[i].size()) continue;
		vector<PII> nd;
		for (int v: t[i]) {
			if (!g[v].size()) {
				no(); return;
			}
			int o = g[v][0];
			for (int j = 1; j <= n; j++)
				if (to[v].find(j) == to[v].find(o) && j != o)
					nd.pb(mp(v, j));
		}
		for (PII z: nd) {
			add(z.fi, z.se);
		}
	}
	if (chk()) {
		puts("Yes");
		for (PII o: e) {
			printf("%d %d\n", o.fi, o.se);
		}
	} else {
		puts("No");
	}
}

int main() {
    int T; read(T);
    while (T--) {
    	read(n);
    	for (int i = 1; i <= n; i++) to[i].init(n);
    	for (int i = 1; i <= n; i++) {
    		for (int j = i + 1; j <= n; j++) {
    			scanf("%s", s + 1);
    			for (int k = 1; k <= n; k++) {
    				if (s[k] == '1')
    					to[k].merge(i, j);
    				inf[k][i][j] = inf[k][j][i] = s[k] - '0';
    			}
    		}
    	}
    	solve();
    }
    return 0;
}