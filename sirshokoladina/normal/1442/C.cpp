#include <bits/stdc++.h>
using namespace std;

struct huge {
	int fs;
	int sc;
};

inline bool operator<(huge a, huge b) {
	if (a.fs < 30 && b.fs < 30) {
		return (1 << a.fs) + a.sc < (1 << b.fs) + b.sc;
	}
	if (a.fs != b.fs) {
		return a.fs < b.fs;
	}
	return a.sc < b.sc;
}

struct edge {
	int to;
	edge *next;
};

const int N = 200000;
const int mod = 998244353;

int n, m;
edge edge_buf[2 * N];
int edge_cnt = 0;
edge *e[2 * N];
huge d[2 * N];
int buf1[N], buf2[N];

inline void add_edge(int from, int to) {
	edge_buf[edge_cnt] = edge{to, e[from]};
	e[from] = &edge_buf[edge_cnt];
	++edge_cnt;
}

inline void update(int *&q_fn, int v, huge value) {
	if (value < d[v]) {
		d[v] = value;
		*q_fn++ = v;
	}
}

int main() {
	#ifdef SG
		freopen("b.in", "r", stdin);
	#endif

	scanf("%d%d", &n, &m);
	for (; m--;) {
		int x, y;
		scanf("%d%d", &x, &y);
		add_edge(2 * x - 2, 2 * y - 2);
		add_edge(2 * y - 1, 2 * x - 1);
	}
	memset(d, 50, sizeof d);
	int *q1_st = buf1, *q1_fn = buf1;
	int *q2_st = buf2, *q2_fn = buf2;
	update(q2_fn, 0, huge{0, 0});
	while (q2_st != q2_fn) {
		if (d[2 * n - 2].fs < N && d[2 * n - 2].fs > 20) {
			break;
		}
		swap(q1_st, q2_st);
		swap(q1_fn, q2_fn);
		while (q1_st != q1_fn) {
			const int &v = *q1_st++;
			update(q2_fn, v ^ 1, huge{d[v].fs + 1, d[v].sc});
			for (edge *it = e[v]; it; it = it->next) {
				update(q1_fn, it->to, huge{d[v].fs, d[v].sc + 1});
			}
		}
	}

	huge res = min(d[2 * n - 2], d[2 * n - 1]);
	int ans = 0;
	for (; res.fs--;) {
		ans = (2 * ans + 1) % mod;
	}
	ans = (ans + res.sc) % mod;
	printf("%d\n", ans);
	
	return 0;
}