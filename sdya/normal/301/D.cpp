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
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 201000;
int p[maxN];
int a[maxN], l[maxN], r[maxN];
int n, m;

int order[maxN];
long long res[maxN];

bool comp(int x, int y) {
	return make_pair(r[x], l[x]) < make_pair(r[y], l[y]);
}

long long t[maxN], add[maxN];
vector < int > d[maxN];

void update(int k, long long delta) {
	for (int i = k; i < maxN; i |= (i + 1)) {
		t[i] += delta;
	}
}

long long get(int k) {
	long long res = 0;
	for (int i = k; i >= 0; i = (i & (i + 1)) - 1) {
		res += t[i];
	}
	return res;
}

long long get(int l, int r) {
	return get(r) - get(l - 1);
}

void update(int i, int l, int r, int cl, int cr, long long value) {
	if (l == cl && r == cr) {
		t[i] += value * (long long)(r - l + 1);
		add[i] += value;
		return ;
	}

	if (cl > (l + r) / 2) {
		update(2 * i + 1, (l + r) / 2 + 1, r, cl, cr, value);
	} else if (cr <= (l + r) / 2) {
		update(2 * i, l, (l + r) / 2, cl, cr, value);
	} else {
		update(2 * i, l, (l + r) / 2, cl, (l + r) / 2, value);
		update(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr, value);
	}
	t[i] = t[2 * i] + t[2 * i + 1] + add[i] * (long long)(r - l + 1);
}

long long get(int i, int l, int r, int cl, int cr) {
	if (cl > cr) {
		return 0;
	}
	if (l == cl && r == cr) {
		return t[i];
	}
	long long sum = (long long)(cr - cl + 1) * add[i];
	if (cl > (l + r) / 2) {
		return sum + get(2 * i + 1, (l + r) / 2 + 1, r, cl, cr);
	}
	if (cr <= (l + r) / 2) {
		return sum + get(2 * i, l, (l + r) / 2, cl, cr);
	}
	return sum 
		+ get(2 * i, l, (l + r) / 2, cl, (l + r) / 2)
		+ get(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		p[a[i]] = i;
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &l[i], &r[i]);
		order[i] = i;
	}
	sort(order + 1, order + m + 1, comp);

	for (int i = 1; i <= n; ++i) {
		for (int j = i + i; j <= n; j += i) {
			d[j].push_back(i);
		}
	}

	int index = 1;
	for (int i = 1; i <= m; ++i) {
		while (index <= n && index <= r[order[i]]) {
			int v = a[index];
			for (int j = v + v; j <= n; j += v) {
				if (p[j] < index) {
					update(p[j], 1);
				}
			}
			for (int j = 0; j < d[v].size(); ++j) {
				int k = d[v][j];
				if (p[k] < index) {
					update(p[k], 1);
				}
			}
			++index;
		}
		res[order[i]] = get(l[order[i]], r[order[i]]);
	}

	for (int i = 1; i <= m; ++i) {
		printf("%I64d\n", res[i] + (long long)(r[i] - l[i] + 1));
	}

	return 0;
}