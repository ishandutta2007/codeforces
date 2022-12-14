#include <bits/stdc++.h>
using namespace std;

const int N = 400005;
int n, m, l[N], id[N], tot;
struct point { int x, y, t; } p[N];
bool operator<(const point &a, const point &b) {
	return a.x == b.x ? a.t < b.t : a.x < b.x;
}

bool cmp(int a, int b) { return l[a] < l[b]; }

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int l, r, t;
		scanf("%d%d%d", &l, &r, &t);
		p[2 * i] = (point) {l, t, 0};
		p[2 * i + 1] = (point) {r, t, 1};
	}
	sort(p, p + 2 * m);
	multiset<int> s;
	for (int i = 0, j; i < 2 * m; i = j) {
		for (j = i; j < 2 * m && p[j].x == p[i].x; j++)
			p[j].t == 0 ? s.insert(p[j].y) : s.erase(s.find(p[j].y));
		if (j < 2 * m && !s.empty()) {
			int y = *s.begin();
			l[++tot] = y - p[j].x;
			l[++tot] = y - p[i].x;
		}
	}
	for (int i = 1; i <= tot; i++) id[i] = i;
	sort(id + 1, id + 1 + tot, cmp);
	int ans = 0, cnt = 0, p = 1;
	while (n--) {
		int t;
		scanf("%d", &t);
		for (; p <= tot && l[id[p]] <= t; p++) {
			int delta = l[id[p]] - l[id[p - 1]];
			ans += delta * cnt;
			id[p] & 1 ? cnt++ : cnt--;
		}
		printf("%d\n", ans + cnt * (t - l[id[p - 1]]));
	}
}