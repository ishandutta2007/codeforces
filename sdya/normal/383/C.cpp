#define _CRT_SECURE_NO_WARNINGS
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

const int maxN = 210000;
int n, m;
vector < int > g[maxN];
int a[maxN], d[maxN];
int t1[4 * maxN], t2[4 * maxN], add1[4 * maxN], add2[4 * maxN];
int cnt;
vector < int > x, y, xa, ya;
int L[maxN], R[maxN], c[maxN];

pair < int, int > pos[maxN];

void update(int t[], int add[], int i, int l, int r, int cl, int cr, int value) {
	if (cl > cr) {
		return ;
	}
	if (l == cl && r == cr) {
		t[i] += value;
		add[i] += value;
		return ;
	}
	if (cl > (l + r) / 2) {
		update(t, add, 2 * i + 1, (l + r) / 2 + 1, r, cl, cr, value);
	} else if (cr <= (l + r) / 2) {
		update(t, add, 2 * i, l, (l + r) / 2, cl, cr, value);
	} else {
		update(t, add, 2 * i, l, (l + r) / 2, cl, (l + r) / 2, value);
		update(t, add, 2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr, value);
	}
	t[i] = max(t[2 * i], t[2 * i + 1]) + add[i];
}

int get(int t[], int add[], int i, int l, int r, int k) {
	if (l == r) {
		return t[i];
	}
	if (k > (l + r) / 2) {
		return get(t, add, 2 * i + 1, (l + r) / 2 + 1, r, k) + add[i];
	}
	return get(t, add, 2 * i, l, (l + r) / 2, k) + add[i];
}

void dfs(int v, int parent = -1) {
	L[v] = cnt;
	c[v] = cnt++;
	if (d[v] % 2 == 0) {
		pos[v] = make_pair(0, x.size());
		x.push_back(v);
		xa.push_back(c[v]);
	} else {
		pos[v] = make_pair(1, y.size());
		y.push_back(v);
		ya.push_back(c[v]);
	}
	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i] == parent) {
			continue;
		}
		d[g[v][i]] = d[v] + 1;
		dfs(g[v][i], v);
	}
	R[v] = cnt - 1;
}

void getBounds(int v, int &l1, int &r1, int &l2, int &r2) {
	l1 = lower_bound(xa.begin(), xa.end(), L[v]) - xa.begin();
	r1 = upper_bound(xa.begin(), xa.end(), R[v]) - xa.begin() - 1;

	l2 = lower_bound(ya.begin(), ya.end(), L[v]) - ya.begin();
	r2 = upper_bound(ya.begin(), ya.end(), R[v]) - ya.begin() - 1;
}

int main() {
	
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);

	for (int i = 1; i <= m; ++i) {
		int mode;
		scanf("%d", &mode);
		if (mode == 2) {
			int v;
			scanf("%d", &v);
			if (pos[v].first == 0) {
				printf("%d\n", a[v] + get(t1, add1, 1, 0, x.size() - 1, pos[v].second));
			} else {
				printf("%d\n", a[v] + get(t2, add2, 1, 0, y.size() - 1, pos[v].second));
			}
		} else {
			int v, val;
			scanf("%d%d", &v, &val);
			int l1, r1, l2, r2;
			getBounds(v, l1, r1, l2, r2);
			int A = val, B = -val;
			if (d[v] % 2 == 1) {
				swap(A, B);
			}
			update(t1, add1, 1, 0, x.size() - 1, l1, r1, A);
			update(t2, add2, 1, 0, y.size() - 1, l2, r2, B);
		}
	}

	return 0;
}