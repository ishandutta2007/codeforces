#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#define Maxn 305
#define P 19260817
#define Inf 2147483647

#define lol unsigned long long
#define Swap(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define Min(x, y) ((x) < (y) ? (x) : (y))
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define Abs(x) ((x) < 0 ? -(x) : (x))

struct Edge {
	int u, v;
} E[Maxn * Maxn];

bool Cmp(Edge A, Edge B) {
	return A.u < B.u;
}

struct List {
	int len, fst[100001], nxt[200001], a[200001], b[200001];
	inline void init(int d) {
		for (int i = 1; i <= d; i++) {
			fst[i] = -1;
		}
		len = 0;
	}
	inline void insert(int _u, int _a, int _b) {
		a[len] = _a;
		b[len] = _b;
		nxt[len] = fst[_u];
		fst[_u] = len++;
	}
};

map<string, int> M;
map<lol, int> H;
List L;
int n, m, k, e, len, ans, a[Maxn], lt[Maxn], id[Maxn][Maxn], sq[Maxn * Maxn], f[Maxn];
lol hsh[Maxn][Maxn];
string s[Maxn];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		a[i] = M[s[i]];
		if (a[i] == 0) {
			a[i] = M[s[i]] = ++k;
			lt[a[i]] = s[i].size();
		}
		len += lt[a[i]];
	}
	len += n - 1;
	L.init(n * n);
	for (int i = 1; i <= n; i++) {
		int t = lt[a[i]] - 1;
		hsh[i][i] = a[i];
		id[i][i] = H[a[i]];
		if (id[i][i] == 0) {
			id[i][i] = H[a[i]] = ++m;
			sq[m] = t;
		}
		L.insert(id[i][i], i, i + 1);
		for (int j = i + 1; j <= n; j++) {
			t += lt[a[j]];
			hsh[i][j] = hsh[i][j - 1] * P + a[j];
			id[i][j] = H[hsh[i][j]];
			if (id[i][j] == 0) {
				id[i][j] = H[hsh[i][j]] = ++m;
				sq[m] = t;
			}
			L.insert(id[i][j], i, j + 1);
		}
	}
	for (int i = 1; i <= m; i++) {
		e = 0;
		for (int j = L.fst[i]; j != -1; j = L.nxt[j]) {
			E[++e] = (Edge){L.a[j], L.b[j]};
		}
		sort(E + 1, E + e + 1, Cmp);
		int p = 1;
		memset(f, 0, sizeof(f));
		for (int j = 1; j <= n + 1; j++) {
			f[j] = Max(f[j], f[j - 1]);
			for (; p <= e && E[p].u == j; p++) {
				f[E[p].v] = Max(f[E[p].v], f[j] + sq[i]);
			}
		}
		if (f[n + 1] == sq[i]) {
			continue;
		}
		ans = Max(ans, f[n + 1]);
	}
	printf("%d\n", len - ans);
	return 0;
}

// By Sooke.
// CF1003F Abbreviation.