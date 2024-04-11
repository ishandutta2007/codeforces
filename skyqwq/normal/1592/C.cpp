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

const int N = 2e5 + 5;

int n, k, a[N], s[N], sum;
 
bool o;

vector<int> g[N];

void inline clear() {
	for (int i = 1; i <= n; i++) g[i].clear();
}

bool dfs(int u, int fa) {
	s[u] = a[u];
	bool t = 0;
	for (int v: g[u]) {
		if (v == fa) continue;
		bool q = dfs(v, u);
		if (t && q) o = 1;
		if (q && s[v] == 0) o = 1;
		t |= q;
		s[u] ^= s[v];
	}
	if (s[u] == sum) t = 1;
	return t;
}

int main() {
	int T; read(T);
	while (T--) {
		read(n), read(k);
		sum = 0;
		for (int i = 1; i <= n; i++) read(a[i]), sum ^= a[i];
		for (int i = 1, u, v; i < n; i++) read(u), read(v), g[u].pb(v), g[v].pb(u);
		if (!sum) puts("YES");
		else if (k == 2) puts("NO");
		else {
			o = 0; dfs(1, 0);
			puts(o ? "YES" : "NO");
		}
		clear();
	}
	return 0;
}