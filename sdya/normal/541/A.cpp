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

const int maxN = 210000;
int n, m;
int l[maxN], r[maxN];
int a[maxN], b[maxN], c[maxN];

int bestLen[maxN], ind[maxN];

bool compA(int x, int y) {
	return make_pair(l[x], r[x]) < make_pair(l[y], r[y]);
}

bool compB(int x, int y) {
	return make_pair(a[x], b[x]) < make_pair(a[y], b[y]);
}

void calculate() {
	vector < int > order(n);
	for (int i = 0; i < n; ++i) {
		order[i] = i + 1;
	}
	sort(order.begin(), order.end(), compA);

	vector < int > order2(m);
	for (int i = 0; i < m; ++i) {
		order2[i] = i + 1;
	}
	sort(order2.begin(), order2.end(), compB);

	int index = 0;
	set < pair < int, int > > S;
	for (int i = 0; i < m; ++i) {
		int id = order2[i];
		while (index < order.size() && l[order[index]] <= a[id]) {
			S.insert(make_pair(-r[order[index]], order[index]));
			++index;
		}

		if (S.empty()) {
			continue;
		}
		int value = -S.begin()->first;

		if (value > a[id]) {
			int len = min(b[id], value) - a[id];
			if (len > bestLen[id]) {
				bestLen[id] = len;
				ind[id] = S.begin()->second;
			}
		}
	}
}

int s[5 * maxN];

pair < int, int > t[20 * maxN];

void init(int i, int l, int r) {
	if (l == r) {
		t[i] = make_pair(0, 0);
		return ;
	}
	init(2 * i, l, (l + r) / 2);
	init(2 * i + 1, (l + r) / 2 + 1, r);
	t[i] = max(t[2 * i], t[2 * i + 1]);
}

void update(int i, int l, int r, int k, pair < int, int > value) {
	if (l == r) {
		t[i] = max(t[i], value);
		return ;
	}

	if (k > (l + r) / 2) {
		update(2 * i + 1, (l + r) / 2 + 1, r, k, value);
	} else {
		update(2 * i, l, (l + r) / 2, k, value);
	}
	t[i] = max(t[2 * i], t[2 * i + 1]);
}

pair < int, int > get(int i, int l, int r, int cl, int cr) {
	if (l == cl && r == cr) {
		return t[i];
	}
	if (cl > (l + r) / 2) {
		return get(2 * i + 1, (l + r) / 2 + 1, r, cl, cr);
	}
	if (cr <= (l + r) / 2) {
		return get(2 * i, l, (l + r) / 2, cl, cr);
	}
	pair < int, int > A = get(2 * i, l, (l + r) / 2, cl, (l + r) / 2);
	pair < int, int > B = get(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr);
	return max(A, B);
}

void calculate2(long long &best, pair < int, int > &ids) {
	int k = 0;
	for (int i = 1; i <= n; ++i) {
		s[k++] = b[i];
	}
	for (int i = 1; i <= m; ++i) {
		s[k++] = r[i];
	}
	sort(s, s + k);
	k = unique(s, s + k) - s;

	vector < int > order(n);
	for (int i = 0; i < n; ++i) {
		order[i] = i + 1;
	}
	sort(order.begin(), order.end(), compA);

	vector < int > order2(m);
	for (int i = 0; i < m; ++i) {
		order2[i] = i + 1;
	}
	sort(order2.begin(), order2.end(), compB);

	int index = 0;
	for (int i = 0; i < n; ++i) {
		int id = order[i];
		int u = lower_bound(s, s + k, r[id]) - s;
		while (index < m && a[order2[index]] <= l[id]) {
			int v = lower_bound(s, s + k, b[order2[index]]) - s;
			update(1, 0, k - 1, v, make_pair(c[order2[index]], order2[index]));
			++index;
		}
		pair < int, int > current = get(1, 0, k - 1, u, k - 1);
		if (current.first > 0) {
			long long t = (long long)(r[id] - l[id]) * (long long)(current.first);
			if (t > best) {
				best = t;
				ids = make_pair(id, current.second);
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &l[i], &r[i]);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
	}

	calculate();
	for (int i = 1; i <= n; ++i) {
		l[i] = -l[i];
		r[i] = -r[i];
		swap(l[i], r[i]);
	}
	for (int i = 1; i <= m; ++i) {
		a[i] = -a[i];
		b[i] = -b[i];
		swap(a[i], b[i]);
	}
	calculate();
	for (int i = 1; i <= n; ++i) {
		l[i] = -l[i];
		r[i] = -r[i];
		swap(l[i], r[i]);
	}
	for (int i = 1; i <= m; ++i) {
		a[i] = -a[i];
		b[i] = -b[i];
		swap(a[i], b[i]);
	}

	long long best = 0;
	pair < int, int > ids = make_pair(-1, -1);

	for (int i = 1; i <= m; ++i) {
		long long value = (long long)(bestLen[i]) * (long long)(c[i]);
		if (value > best) {
			best = value;
			ids = make_pair(ind[i], i);
		}
	}

	calculate2(best, ids);

	if (best == 0) {
		printf("0\n");
		return 0;
	} else {
		cout << best << endl;
		cout << ids.first << " " << ids.second << endl;
	}

	return 0;
}