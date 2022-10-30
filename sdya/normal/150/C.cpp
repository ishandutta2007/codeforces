#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 160000;
double s[4 * maxN], t[4 * maxN], l[4 * maxN], r[4 * maxN];

struct Q {
	double s, t, l, r;
	Q() {
	}
	Q(double s, double t, double l, double r) : s(s), t(t), l(l), r(r) {
	}
	void build(Q L, Q R) {
		s = L.s + R.s;
		t = max(L.t, R.t);
		t = max(t, L.r + R.l);
		l = max(L.l, L.s + R.l);
		r = max(R.r, L.r + R.s);
	}
};

Q get(int i, int l, int r, int cl, int cr) {
	if (l == cl && r == cr) {
		return Q(s[i], t[i], ::l[i], ::r[i]);
	}
	if (cl > (l + r) / 2) {
		return get(2 * i + 1, (l + r) / 2 + 1, r, cl, cr);
	}
	if (cr <= (l + r) / 2) {
		return get(2 * i, l, (l + r) / 2, cl, cr);
	}

	Q L = get(2 * i, l, (l + r) / 2, cl, (l + r) / 2);
	Q R = get(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr);
	Q res;
	res.build(L, R);
	return res;
}

void update(int i, int l, int r, int k, double delta) {
	if (l == r) {
		s[i] += delta;
		::l[i] = max(::l[i], delta);
		::r[i] = max(::r[i], delta);
		t[i] = max(t[i], delta);
		return ;
	}
	if (k > (l + r) / 2) {
		update(2 * i + 1, (l + r) / 2 + 1, r, k, delta);
	} else  {
		update(2 * i, l, (l + r) / 2, k, delta);
	}
	Q L(s[2 * i], t[2 * i], ::l[2 * i], ::r[2 * i]);
	Q R(s[2 * i + 1], t[2 * i + 1], ::l[2 * i + 1], ::r[2 * i + 1]);
	Q res;
	res.build(L, R);
	s[i] = res.s;
	t[i] = res.t;
	::l[i] = res.l;
	::r[i] = res.r;
}

int n, m, c;
double a[maxN];
int x[maxN];
int p[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &c);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &x[i]);
	}
	for (int i = 1; i < n; ++i) {
		scanf("%d", &p[i]);
		update(1, 1, n - 1, i, (double)(x[i + 1] - x[i]) / 2.0 - (double)(p[i]) / 100.0 * (double)(c));
	}

	double res = 0.0;
	for (int i = 1; i <= m; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		res += get(1, 1, n - 1, l, r - 1).t;
	}
	printf("%.10lf\n", res);


	return 0;
}