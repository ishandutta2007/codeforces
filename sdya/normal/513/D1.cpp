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

const int maxN = 1100000;
int n, m;
vector < int > l[maxN], r[maxN];
char s[10];

int minV[maxN], maxV[maxN];
bool used[maxN];

int lt[maxN], rt[maxN];

void print(int v) {
	if (lt[v] != 0) {
		print(lt[v]);
	}
	printf("%d ", v);
	if (rt[v] != 0) {
		print(rt[v]);
	}
}

int tMin[4 * maxN], tMax[4 * maxN];

void build(int t[], int i, int l, int r, bool isMax) {
	if (l == r) {
		t[i] = l;
		return ;
	}
	build(t, 2 * i, l, (l + r) / 2, isMax);
	build(t, 2 * i + 1, (l + r) / 2 + 1, r, isMax);
	if (isMax) {
		t[i] = max(t[2 * i], t[2 * i + 1]);
	} else {
		t[i] = min(t[2 * i], t[2 * i + 1]);
	}
}

void update(int t[], int i, int l, int r, int k, int value, bool isMax) {
	if (l == r) {
		t[i] = value;
		return ;
	}
	if (k > (l + r) / 2) {
		update(t, 2 * i + 1, (l + r) / 2 + 1, r, k, value, isMax);
	} else {
		update(t, 2 * i, l, (l + r) / 2, k, value, isMax);
	}
	if (isMax) {
		t[i] = max(t[2 * i], t[2 * i + 1]);
	} else {
		t[i] = min(t[2 * i], t[2 * i + 1]);
	}
}

int get(int t[], int i, int l, int r, int cl, int cr, bool isMax) {
	if (l == cl && r == cr) {
		return t[i];
	}
	if (cl > (l + r) / 2) {
		return get(t, 2 * i + 1, (l + r) / 2 + 1, r, cl, cr, isMax);
	}
	if (cr <= (l + r) / 2) {
		return get(t, 2 * i, l, (l + r) / 2, cl, cr, isMax);
	}
	int A = get(t, 2 * i, l, (l + r) / 2, cl, (l + r) / 2, isMax);
	int B = get(t, 2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr, isMax);
	if (isMax) {
		return max(A, B);
	} else {
		return min(A, B);
	}
}

void dfs(int v) {
	if (used[v]) {
		return ;
	}
	used[v] = true;
	minV[v] = v;
	maxV[v] = v;
	for (int i = 0; i < l[v].size(); ++i) {
		dfs(l[v][i]);
		minV[v] = min(minV[v], get(tMin, 1, 1, n, v, maxV[l[v][i]], false));
		maxV[v] = max(maxV[v], get(tMax, 1, 1, n, v, maxV[l[v][i]], true));
	}
	for (int i = 0; i < r[v].size(); ++i) {
		dfs(r[v][i]);
		minV[v] = min(minV[v], get(tMin, 1, 1, n, v, maxV[r[v][i]], false));
		maxV[v] = max(maxV[v], get(tMax, 1, 1, n, v, maxV[r[v][i]], true));
	}
	update(tMin, 1, 1, n, v, minV[v], false);
	update(tMax, 1, 1, n, v, maxV[v], true);
}

void build(int n, int shift, int R) {
	if (n <= 1) {
		return ;
	}

	{
		bool isOk = true;
		int u = shift + 1;
		int value = u;
		for (int i = 0; i < l[u].size(); ++i) {
			value = max(value, get(tMax, 1, 1, ::n, u + 1, maxV[l[u][i]], true));
		}
		int m = value - u;
		for (int i = 0; i < r[u].size(); ++i) {
			if (r[u][i] <= value) {
				isOk = false;
			}
		}
		if (isOk) {
			if (m != 0 && 2 <= n) {
				lt[u] = shift + 2;
			}
			if (m + 2 <= n) {
				rt[u] = shift + m + 2;
			}
			build(m, shift + 1, shift + m + 1);
			build(n - 1 - m, shift + m + 1, R);
			return ;
		}
	}
	printf("IMPOSSIBLE\n");
	exit(0);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		scanf("%s", &s);
		if (u >= v) {
			printf("IMPOSSIBLE\n");
			return 0;
		}
		if (s[0] == 'L') {
			l[u].push_back(v);
		} else {
			r[u].push_back(v);
		}
	}

	build(tMin, 1, 1, n, false);
	build(tMax, 1, 1, n, true);
	for (int i = n; i >= 1; --i) {
		dfs(i);
	}

	for (int i = 1; i <= n; ++i) {
		pair < int, int > a(maxN - 1, -1);
		pair < int, int > b(maxN - 1, -1);
		for (int j = 0; j < l[i].size(); ++j) {
			a.first = min(a.first, minV[l[i][j]]);
			a.second = max(a.second, maxV[l[i][j]]);
		}
		for (int j = 0; j < r[i].size(); ++j) {
			b.first = min(b.first, minV[r[i][j]]);
			b.second = max(b.second, maxV[r[i][j]]);
		}
		if (a.second >= b.first) {
			printf("IMPOSSIBLE\n");
			return 0;
		}
	}

	build(n, 0, n);
	print(1);
	printf("\n");

	return 0;
}