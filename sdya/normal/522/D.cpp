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

const int maxN = 510000;
const int inf = 1000000000;
int n, m, a[maxN];
int b[maxN], k;
int p[maxN];

vector < int > q[maxN];

vector < pair < int, int > > t[4 * maxN];
vector < int > h[4 * maxN];

void build(int i, int l, int r) {
	if (l == r) {
		if (p[l] <= n) {
			t[i].assign(1, make_pair(p[l], p[l] - l));
			h[i].assign(1, p[l] - l);
		}
		return ;
	}
	build(2 * i, l, (l + r) / 2);
	build(2 * i + 1, (l + r) / 2 + 1, r);
	t[i].resize(t[2 * i].size() + t[2 * i + 1].size());
	merge(t[2 * i].begin(), t[2 * i].end(), t[2 * i + 1].begin(), t[2 * i + 1].end(), t[i].begin());
	h[i].resize(t[i].size());
	for (int j = 0; j < h[i].size(); ++j) {
		h[i][j] = t[i][j].second;
		if (j > 0) {
			h[i][j] = min(h[i][j], h[i][j - 1]);
		}
	}
}

int get(int i, int l, int r, int cl, int cr, int bound) {
	if (l == cl && r == cr) {
		int index = upper_bound(t[i].begin(), t[i].end(), make_pair(bound, inf)) - t[i].begin();
		--index;

		if (index >= 0) {
			return h[i][index];
		}
		return inf;
	}

	if (cl > (l + r) / 2) {
		return get(2 * i + 1, (l + r) / 2 + 1, r, cl, cr, bound);
	}
	if (cr <= (l + r) / 2) {
		return get(2 * i, l, (l + r) / 2, cl, cr, bound);
	}

	int A = get(2 * i, l, (l + r) / 2, cl, (l + r) / 2, bound);
	int B = get(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr, bound);
	return min(A, B);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		b[k++] = a[i];
	}
	sort(b, b + k);
	k = unique(b, b + k) - b;
	for (int i = 1; i <= n; ++i) {
		a[i] = lower_bound(b, b + k, a[i]) - b;
	}

	for (int i = 1; i <= n; ++i) {
		p[i] = n + 1;
		q[a[i]].push_back(i);
	}

	for (int i = 0; i < k; ++i) {
		for (int j = 0; j + 1 < q[i].size(); ++j) {
			p[q[i][j]] = q[i][j + 1];
		}
	}
	build(1, 1, n);
	for (int i = 1; i <= m; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		int res = get(1, 1, n, l, r, r);
		if (res == inf) {
			res = -1;
		}
		printf("%d\n", res);
	}

	return 0;
}