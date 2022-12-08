#include <bits/stdc++.h>

using namespace std;

struct node {
	int minm;
	vector<int> num;
};

struct node s[105];

struct node *p[105];

int cmp(node *p1, node *p2) {
	return p1->minm > p2->minm;
}

void solve() {
	int n, m;
	int a[105];
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		p[i] = &s[i];
		p[i]->minm = 1e9 + 7;
		p[i]->num.clear();
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[j]);
		}
		sort(a, a + m);
		sort(p, p + m, cmp);
		for (int j = 0; j < m; ++j) {
			p[j]->num.push_back(a[j]);
			p[j]->minm = min(p[j]->minm, a[j]);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%d ", p[j]->num[i]);
		}
		printf("\n");
	}
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