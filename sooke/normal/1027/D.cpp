#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

typedef long long lol;
typedef long double lod;

inline char readLetter() {
	char c = getchar();
	while ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z')) { c = getchar(); }
	return c;
}
inline int read() {
	char c = getchar(); int n = 0, f = 0;
	while (c < '0' || c > '9') { if (c == '-') { f = 1; } c = getchar(); }
	while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
	return f ? -n : n;
}

const int maxInt = 2147483647;
const lol maxLongLong = 9223372036854775807LL;
const int maxN = 200005;

int n, ans, a[maxN], nxt[maxN];
bool vis[maxN];
int used[maxN];

void newLoop(int u, int s, int min) {
	if (used[u] > 0) {
		if (used[u] == s) {
			ans += min;
		}
		return;
	}
	used[u] = s;
	newLoop(nxt[u], s, std::min(min, a[u]));
}
void dfs(int u) {
	if (vis[u]) {
		if (!used[u]) {
			newLoop(u, u, maxInt);
		}
		return;
	}
	vis[u] = true;
	dfs(nxt[u]);
}

int main() {
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	for (int i = 1; i <= n; i++) {
		nxt[i] = read();
	}
	for (int i = 1; i <= n; i++) {
		dfs(i);
	}
	std::cout << ans << std::endl;
	return 0;
}

// By Sooke.
// CF1027D Mouse Hunt.