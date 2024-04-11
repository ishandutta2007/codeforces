#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 600000;

int t1[4 * maxN], v1[4 * maxN], t2[4 * maxN], v2[4 * maxN];

void push(int t[], int v[], int i, int l, int r) {
	if (v[i] != 0 && l != r) {
		t[2 * i] = v[i];
		t[2 * i + 1] = v[i];

		v[2 * i] = v[i];
		v[2 * i + 1] = v[i];
	}
	v[i] = 0;
}

void update(int t[], int v[], int i, int l, int r, int cl, int cr, int value) {
	if (l == cl && r == cr) {
		v[i] = value;
		t[i] = value;
		return ;
	}

	push(t, v, i, l, r);

	if (cl > (l + r) / 2) {
		update(t, v, 2 * i + 1, (l + r) / 2 + 1, r, cl, cr, value);
	} else if (cr <= (l + r) / 2) {
		update(t, v, 2 * i, l, (l + r) / 2, cl, cr, value);
	} else {
		update(t, v, 2 * i, l, (l + r) / 2, cl, (l + r) / 2, value);
		update(t, v, 2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr, value);
	}

	t[i] = max(t[2 * i], t[2 * i + 1]);
}

int get(int t[], int v[], int i, int l, int r, int cl, int cr) {
	if (l == cl && r == cr) {
		return t[i];
	}
	push(t, v, i, l, r);

	if (cl > (l + r) / 2) {
		return get(t, v, 2 * i + 1, (l + r) / 2 + 1, r, cl, cr);
	}
	if (cr <= (l + r) / 2) {
		return get(t, v, 2 * i, l, (l + r) / 2, cl, cr);
	}

	int A = get(t, v, 2 * i, l, (l + r) / 2, cl, (l + r) / 2);
	int B = get(t, v, 2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr);
	return max(A, B);
}

vector < int > g[maxN];
int tin[maxN], tout[maxN];
vector < int > order;
bool used[maxN];
int n, cnt;

void dfs(int v) {
	used[v] = true;
	tin[v] = order.size();
	order.push_back(v);

	for (int i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i]]) {
			dfs(g[v][i]);
		}
	}
	tout[v] = order.size() - 1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1);

	int m;
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		int c, v;
		scanf("%d%d", &c, &v);
		if (c == 1) {
			update(t1, v1, 1, 0, n - 1, tin[v], tout[v], i);
		}
		if (c == 2) {
			update(t2, v2, 1, 0, n - 1, tin[v], tin[v], i);
		}
		if (c == 3) {
			int x = get(t1, v1, 1, 0, n - 1, tin[v], tin[v]);
			int y = get(t2, v2, 1, 0, n - 1, tin[v], tout[v]);

			if (x > y) {
				printf("1\n");
			} else {
				printf("0\n");
			}
		}
	}
	

	return 0;
}