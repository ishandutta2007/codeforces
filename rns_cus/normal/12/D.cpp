///	Choe Kwang D

#include <bits/stdc++.h>
using namespace std;
#define N 500500
#define inf 1000000000

struct pnt{
	int x, y, z;
	void print() {
		printf("%d %d %d\n", x, y, z);
	}
} p[N];

bool operator < (pnt A, pnt B) {
	return (A.x != B.x) ? (A.x < B.x) : (A.y != B.y) ? (A.y < B.y) : (A.z < B.z);
}

int a[N], b[N], n, x[N], y[N], z[N];
int gx[N], gy[N], num[N], now[N], sx[N], sy[N];
int id[N], d[N], dd[N];
int f[N];

void init(int n) {
	for (int i = 0; i <= n; i ++) a[i] = b[i] = x[i] = y[i] = z[i] = gx[i] = gy[i] = num[i] = now[i] = 0;
	for (int i = 0; i <= n; i ++) sx[i] = sy[i] = d[i] = dd[i] = 0;
}

void add(int k, int val) {
	while (k < N) {
		f[k] = min(f[k], val);
		k += k & -k;
	}
}

int count(int k) {
	int r = inf;
	while (k) {
		r = min(f[k], r);
		k -= k & -k;
	}
	return r;
}

bool cmp(int i, int j) {
	return d[i] < d[j];
}

void calc_dd() {
	sort(id, id + n, cmp);
	dd[id[0]] = 1;
	int num = 1;
	for (int i = 1; i < n; i ++) {
		if (d[id[i]] == d[id[i-1]]) dd[id[i]] = num;
		else dd[id[i]] = ++num;
	}
}

int main() {

#define debugd
#ifdef debug
int t;
scanf("%d", &t);
while (t --) {
#endif // debug
	scanf("%d", &n);
	init(n);
	for (int i = 0; i < n; i ++) scanf("%d", &x[i]);
	for (int i = 0; i < n; i ++) scanf("%d", &y[i]);
	for (int i = 0; i < n; i ++) scanf("%d", &z[i]);
	for (int i = 0; i < n; i ++) x[i] = inf - x[i], y[i] = inf - y[i], z[i] = inf - z[i];

	for (int i = 0; i < n; i ++) id[i] = i, d[i] = x[i];
	calc_dd();
	for (int i = 0; i < n; i ++) p[i].x = dd[i];

	for (int i = 0; i < n; i ++) id[i] = i, d[i] = y[i];
	calc_dd();
	for (int i = 0; i < n; i ++) p[i].y = dd[i];

	for (int i = 0; i < n; i ++) id[i] = i, d[i] = z[i];
	calc_dd();
	for (int i = 0; i < n; i ++) p[i].z = dd[i];

	sort(p, p + n);
//	for (int i = 0; i < n; i ++) p[i].print();

	for (int i = 0; i < n; i ++) gx[p[i].x] ++;
	int cnx = 0;
	for (int i = 0; i < n; i ++) if (gx[i]) cnx = i;
	for (int i = 1; i <= cnx; i ++) sx[i] = sx[i-1] + gx[i];

	for (int i = 0; i < n; i ++) gy[p[i].y] ++;
	int cny = 0;
	for (int i = 0; i < n; i ++) if (gy[i]) cny = i;
	for (int i = 1; i <= cny; i ++) sy[i] = sy[i-1] + gy[i];
	for (int i = 0; i < n; i ++) {
		num[i] = sy[p[i].y-1] + (++now[p[i].y]);
	}

	for (int i = 0; i <= n; i ++) f[i] = inf;
	int ans = 0, runs = 0;
	d[runs++] = 0;
	for (int i = 1; i < n; i ++) {
		if (p[i].x > p[i-1].x) {
			for (int j = 0; j < runs; j ++) add(num[d[j]], p[d[j]].z);
			runs = 0;
			d[runs++] = i;
		}
		else d[runs++] = i;
		int mn = sy[p[i].y-1];
		if (count(mn) < p[i].z) ans ++;
	}
	printf("%d\n", ans);
#ifdef debug
}
#endif // debug
	return 0;
}