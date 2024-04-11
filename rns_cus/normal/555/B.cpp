#include <cstdio>
#include <algorithm>
#include <set>

#define N 200100

using namespace std;

typedef __int64 LL;

LL l[N], r[N];
LL x[N];

int id[N], rid[N];

set <int> SS;

bool cmp(int a, int b) { return x[a] < x[b]; }

struct itv {
	int L, R, id;
	itv (int L = 0, int R = 0, int i = 0) : L(L), R(R), id(i) {}
	bool operator < (const itv &I) const { return R < I.R; }
} p[N];

int rlt[N];

main() {
//	freopen("B.in", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%I64d %I64d", l + i, r + i);
	for (int i = 1; i <= m; i ++) {
		scanf("%I64d", x + i);
		id[i] = i, SS.insert(i);
	}
	sort(id + 1, id + m + 1, cmp);
	sort(x + 1, x + m + 1);

	for (int i = 1; i < n; i ++) {
		LL lo = l[i + 1] - r[i];
		LL hi = r[i + 1] - l[i];
		int S = lower_bound(x + 1, x + m + 1, lo) - x;
		int E = upper_bound(x + 1, x + m + 1, hi) - x - 1;
		if (S > E) {
			puts("No");
			return 0;
		}
		p[i] = itv(S, E, i);
	}
	sort(p + 1, p + n);
	for (int i = 1; i < n; i ++) {
		set <int>::iterator it = SS.lower_bound(p[i].L);
		if (it == SS.end()) { return puts("No"); }
		if (*it > p[i].R) { return puts("No"); }
		rlt[p[i].id] = id[*it], SS.erase(it);
	}
	puts("Yes");
	for (int i = 1; i < n; i ++) printf("%d ", rlt[i]);
}