#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

#define SQR(x) ((x) * (x))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define LOWBIT(x) ((x) & -(x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define SWAP(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define MAXINT 2147483647
#define MAXLOL 9223372036854775807LL
#define INF MAXINT
#define lol long long
#define lod long double

inline int read01() {
	char c = getchar();
	int n = 0;
	while (c != '0' && c != '1') {
		c = getchar();
	}
	while (c == '0' || c == '1') {
		n = (n << 1) + (c ^ 48);
		c = getchar();
	}
	return n;
}
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

#define MAXN 15
#define MAXM 5005
#define MAXQ 500005

int n, m, q, w[MAXN], cnt[MAXM], ans[MAXQ];

struct Query {
	int id, s, k;
} Q[MAXQ];

struct Res {
	int val, cnt;
} R[MAXM];

bool cmp(Query A, Query B) {
	return A.s == B.s ? A.k < B.k : A.s < B.s;
}
bool cmpr(Res A, Res B) {
	return A.val < B.val;
}

void solve(int k) {
	for (int i = 0; i <= 4095; i++) {
		if (cnt[i] == 0) {
			R[i].val = INF;
			continue;
		}
		R[i].val = 0;
		R[i].cnt = cnt[i];
		for (int j = 0; j < n; j++) {
			R[i].val += ((k & (1 << j)) == (i & (1 << j))) * w[j];
		}
	}
	std::sort(R, R + 4095 + 1, cmpr);
}

int main() {
	n = read(), m = read(), q = read();
	for (int i = n - 1; i >= 0; i--) {
		w[i] = read();
	}
	for (int i = 1; i <= m; i++) {
		cnt[read01()]++;
	}
	for (int i = 1; i <= q; i++) {
		Q[i].id = i;
		Q[i].s = read01(), Q[i].k = read();
	}
	std::sort(Q + 1, Q + q + 1, cmp);
	Q[0].s = -1;
	for (int i = 1, j, sum; i <= q; i++) {
		if (Q[i - 1].s != Q[i].s) {
			solve(Q[i].s);
			j = -1;
			sum = 0;
		}
		while (j < 4095 && R[j + 1].val <= Q[i].k) {
			j++;
			sum += R[j].cnt;
		}
		ans[Q[i].id] = sum;
	}
	for (int i = 1; i <= q; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}

// By Sooke.
// CF1017D The Wu.