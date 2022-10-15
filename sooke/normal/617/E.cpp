#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define LOWBIT(x) ((x) & -(x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define SWAP(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define lol long long

inline int read() {
	char c = getchar();
	int n = 0, f = 0;
	while (c < '0' || c > '9') {
		if (c == '-') {
			f = 1;
		}
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		n = (n << 1) + (n << 3) + (c ^ 48);
		c = getchar();
	}
	return f ? -n : n;
}

#define MAXN 100005

int n, m, k, siz, a[MAXN], pre[MAXN], pos[MAXN], cnt[1 << 20];
lol ans[MAXN], cur;

struct Query {
	int l, r, id;
};

bool cmp(Query A, Query B) {
	return pos[A.l] == pos[B.l] ? A.r < B.r : A.l < B.l;
}

Query Q[MAXN];

inline void modify(int d, int p) {
	if (p == 1) {
		cur += cnt[pre[d] ^ k];
		cnt[pre[d]]++;
	} else {
		cnt[pre[d]]--;
		cur -= cnt[pre[d] ^ k];
	}
}

int main() {
	n = read(), m = read(), k = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		pre[i] = pre[i - 1] ^ a[i];
	}
	for (int i = 1; i <= m; i++) {
		Q[i].id = i;
		Q[i].l = read() - 1, Q[i].r = read();
	}
	siz = floor(sqrt(n));
	for (int i = 1; i <= n; i++) {
		pos[i] = (i - 1) / siz + 1;
	}
	sort(Q + 1, Q + m + 1, cmp);
	for (int i = 1, l = 1, r = 0; i <= m; i++) {
		while (l < Q[i].l) {
			modify(l++, -1);
		}
		while (l > Q[i].l) {
			modify(--l, 1);
		}
		while (Q[i].r < r) {
			modify(r--, -1);
		}
		while (Q[i].r > r) {
			modify(++r, 1);
		}
		ans[Q[i].id] = cur;
	}
	for (int i = 1; i <= m; i++) {
		printf("%I64d\n", ans[i]);
	}
	return 0;
}

// By Sooke.
// CF617E XOR and Favorite Number.