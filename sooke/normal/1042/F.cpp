#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

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
const lol maxLongLong = 9223372036854775807ll;
const int maxN = 1000005;

int n, k, root, ans = 1, deg[maxN], dis[maxN];

struct List {
	int len, fst[maxN], nxt[maxN << 1], v[maxN << 1];
	
	List() { memset(fst, -1, sizeof(fst)); }
	inline void insert(int u, int vv) { v[len] = vv, nxt[len] = fst[u], fst[u] = len++; }
	inline void connect(int u, int vv) { insert(u, vv), insert(vv, u); }
} ls;

void dfs(int u, int fa) {
	if (deg[u] == 1) { dis[u] = 0; return; }
	std::vector<int> vec;
	for (int i = ls.fst[u]; ~i; i = ls.nxt[i]) {
		int v = ls.v[i];
		if (v != fa) {
			dfs(v, u);
			vec.push_back(dis[v] + 1);
		}
	}
	std::sort(vec.begin(), vec.end());
	dis[u] = vec[(int)vec.size() - 1];
	for (int i = (int)vec.size() - 1; i >= 1; i--) {
		if (vec[i] + vec[i - 1] > k) { ans++; dis[u] = vec[i - 1]; }
		else { break; }
	}
	vec.clear();
}

int main() {
	n = read(), k = read();
	for (int i = 2; i <= n; i++) {
		int u = read(), v = read();
		ls.connect(u, v);
		deg[u]++, deg[v]++;
		if (deg[u] == 2) { root = u; }
		else if (deg[v] == 2) { root = v; }
	}
	if (root) { dfs(root, 0); }
	std::cout << ans << std::endl;
	return 0;
}