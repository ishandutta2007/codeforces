#include <bits/stdc++.h>
using namespace std;

#define N 100020
typedef pair <int, int> pii;

int a, b, h, w, n, e[N], x, y;
pii sample;

bool cmp(int x, int y) {
	return x > y;
}

pii func(pii a) {
	if (a.first <= a.second) return a;
	return make_pair(a.second, a.first);
}

bool ok(pii a) {
	return (a.first <= sample.first && a.second <= sample.second);
}

vector <pii> v[99];

int main() {
	scanf("%d %d %d %d %d", &a, &b, &h, &w, &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &e[i]);
	sort (e + 1, e + n + 1, cmp);
	v[0].push_back(func(make_pair(a, b)));
	sample = func(make_pair(h, w));
    for (int i = 0; i <= n; i ++) {
		int sz = v[i].size();
		sort (v[i].begin(), v[i].end());
		for (int j = 0; j < sz; j ++) {
			if (ok(v[i][j])) {
				printf("%d\n", i);
				return 0;
			}
		}
		if (i == n) {
			puts("-1");
			return 0;
		}
        for (int j = 0; j < sz; j ++) if (!j || v[i][j] != v[i][j-1]) {
        	x = v[i][j].first;
			y = v[i][j].second;
            v[i+1].push_back(func(make_pair(x, (y + e[i+1] - 1) / e[i+1])));
            v[i+1].push_back(func(make_pair((x + e[i+1] - 1) / e[i+1], y)));
        }
    }
	return 0;
}