#include <cstdio>
#include <algorithm>

using namespace std;

#define N 100005

typedef __int64 LL;

struct Point {
	int x, y;
	Point(int x = 0, int y = 0) : x(x), y(y) {}
	bool operator < (const Point &p) const {
		return y < p.y;
	}
} p[N], sto[N];

int cnt;

bool cmp(Point a, Point b) { return a.x < b.x; }

int calc(int m) {
	int mn = 1 << 30;
	for (int b = 0; b <= m; b ++) {
		int t = m - b;
		int tmp = (sto[cnt - t].y - sto[b + 1].y + 1) / 2;
		if (mn > tmp) mn = tmp;
	}
	return mn;
}

void add(int x) {
	int pos = lower_bound(sto + 1, sto + cnt + 1, Point(0, p[x].y)) - sto;
	for (int i = cnt + 1; i > pos; i --) sto[i] = sto[i - 1];
	sto[pos] = p[x];
	cnt ++;
}

main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		p[i] = Point(a + c, b + d);
	}
	sort(p + 1, p + n + 1, cmp);
	LL rlt = 1LL << 62;
	for (int l = 0; l <= m; l ++) {
		cnt = n - m;
		for (int i = 1; i <= cnt; i ++) sto[i] = p[i + l];
		sort(sto + 1, sto + cnt + 1);
		for (int r = m - l; r >= 0; r --) {
			int rem = m - l - r;
			int h = max(1, calc(rem));
			int w = max(1, (p[n - r].x - p[l + 1].x + 1) / 2);
			if (rlt > 1LL * w * h) rlt = 1LL * w * h;
			if (r) add(n + 1 - r);
		}
	}
	printf("%I64d\n", rlt);
}