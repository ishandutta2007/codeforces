// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e3 + 5;

int n;

vector<int> g[N];

typedef pair<int, int> PII;

PII e[N];
 
int inline ask(vector<int> b) {
	int k = b.size();
	printf("? %d", k);
	for (int v: b) printf(" %d", v);
	puts("");
	fflush(stdout);
	int x; read(x);
	return x;
}

int t;

void dfs1(int u, int fa) {
	int f = 0;
	for (int v: g[u]) {
		if (v == fa) continue;
		e[++t] = mp(u, v);
		dfs1(v, u);
	}
}

int ans;

bool vis[N];

bool inline chk(int x) {
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= x; i++)
		vis[e[i].fi] = vis[e[i].se] = 1;
	vector<int> t;
	for (int i = 1; i <= n; i++) if (vis[i]) t.pb(i);
	return ask(t) == ans;
}

int main() {
	read(n); 
	for (int i = 1, u, v; i < n; i++)
		read(u), read(v), g[u].pb(v), g[v].pb(u);
	dfs1(1, 0);
	vector<int> p;
	for (int i = 1; i <= n; i++) p.pb(i);
	ans = ask(p);
	int l = 1, r = t;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (chk(mid)) r = mid;
		else l = mid + 1;
	}
	printf("! %d %d\n", e[r].fi, e[r].se);
	fflush(stdout);
	return 0;	
}