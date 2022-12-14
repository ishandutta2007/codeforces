#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double ldb;
#define M 300010
#define ep 1e-9
#define INF 1e9
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)

int n, m, tmp[M];
vector <int> con[M];

struct Test {
	int p, t, id;
	Test (int p = 0, int t = 0, int id = 0) : p(p), t(t), id(id) {}
	bool operator < (Test a) const {
		if (1LL * p * a.t != 1LL * a.p * t) return (1LL * p * a.t > 1LL * a.p * t);
		return id < a.id;
	}
} test[M];

ldb tot, p[M], minS[M], maxS[M], mx[M], mn[M];

inline void add_min(int x, ldb v) {for (int i = x; i; i -= (i & -i)) mn[x] = min(mn[x], v);}
inline ldb calc_min(int x) {
	ldb res = INF;
	for (int i = x; i <= n; i += (i & -i)) res = min(res, mn[x]);
	return res;
}

inline void add_max(int x, ldb v) {for (int i = x; i <= n; i += (i & -i)) mx[x] = max(mx[x], v);}
inline ldb calc_max(int x) {
	ldb res = 0;
	for (int i = x; i; i -= (i & -i)) res = max(res, mx[x]);
	return res;
}

bool check(ldb c) {

	ldb T = 0, st, en, tp;
	for (int i = 1; i <= n; i++) mx[i] = 0, mn[i] = INF;
	for (int i = 1; i <= m; i++) {
		ldb dt = 0;
		int cnt = 0;
		for (int j = 0; j < con[i].size(); j++)
			dt += test[con[i][j]].t, p[cnt++] = test[con[i][j]].p;
		for (int j = 0; j < con[i].size(); j++) {
			int k = con[i][j];
			maxS[k] = test[k].p * (1 - c * (T + test[k].t) / tot);
			minS[k] = test[k].p * (1 - c * (T + dt) / tot);
		}

		if (cnt > 1) {
			ldb a = 1 - c * (T + dt) / tot;
			for (int j = 0; j < con[i].size(); j++) {
				int k = con[i][j];
				tp = maxS[k] / a;
				st = min(tp, test[k].p), en = max(tp, test[k].p);
				if (lower_bound(p, p + cnt, en - ep) - lower_bound(p, p + cnt, st + ep) >= 1) return 0;
			}
		}
		for (int j = 0; j < con[i].size(); j++) {
			int k = con[i][j];
			tp = calc_min(test[k].id + 1);
			if (tp < maxS[k] - ep) return 0;
			tp = calc_max(test[k].id - 1);
			if (tp > minS[k] + ep) return 0;
		}
		for (int j = 0; j < con[i].size(); j++) {
			int k = con[i][j];
			add_min(test[k].id, minS[k]);
			add_max(test[k].id, maxS[k]);
		}
		T += dt;
	}
	return 1;
}

int main() {
	//freopen("D.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &test[i].p), tmp[i] = test[i].p;
	for (int i = 0; i < n; i++) scanf("%d", &test[i].t), tot += test[i].t;
	sort(tmp, tmp + n);
	int tn = unique(tmp, tmp + n) - tmp;
	for (int i = 0; i < n; i++)
		test[i].id = lower_bound(tmp, tmp + tn, test[i].p) - tmp + 1;
	sort(test, test + n);
	int lp = test[0].p, lt = test[0].t;
	con[++m].push_back(0);
	for (int i = 1; i < n; i++) {
		if (1LL * test[i].p * lt != 1LL * test[i].t * lp) {
			con[++m].push_back(i); lt = test[i].t, lp = test[i].p;
		}
		else con[m].push_back(i);
	}

	ldb l = 0, r = 1;
	for (int step = 0; step < 40; step++) {
		ldb mid = (l + r) / 2;
		if (check(mid)) l = mid;
		else r = mid;
	}
	printf("%.12lf\n", (double)(l));
}