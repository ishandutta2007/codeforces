#include <bits/stdc++.h>

using namespace std;

struct dt {
	int h;
	int p;
} d[100005];

int cmp(int x, int y) {
	return d[x].h > d[y].h;
}


struct pt {
	long long sum;
	int id;
} p[100005];

int cmp1(pt x, pt y) {
	return x.sum < y.sum;
}

void solve() {
	printf("YES\n");
	int n, m, x;
	scanf("%d%d%d", &n, &m, &x);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &d[i].h);
	}
	vector<int> l;
	for (int i = 0; i < n; ++i) {
		l.push_back(i);
	}
	sort(l.begin(), l.end(), cmp);
	memset(p, 0, sizeof p);
	for (int i = 1; i <= n; ++i) {
		p[i].id = i;
	}
	for (int i = 0; i < n; ++i) {
		if (i % m == 0) {
			sort(p + 1, p + 1 + m, cmp1);
		}
		d[l[i]].p = p[i % m + 1].id;
		p[i % m + 1].sum += d[l[i]].h;
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ", d[i].p);
	}
	printf("\n");
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}