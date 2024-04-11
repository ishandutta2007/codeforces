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

const int maxN = 510000;
int n, h[maxN];
vector < int > g[maxN];
vector < int > gr[maxN];
int used[maxN];

int m, a[maxN], b[maxN], cnt[maxN];
int k;

void dfs(int v) {
	used[v] = true;
	for (int i = 0; i < gr[v].size(); ++i) {
		if (!used[gr[v][i]]) {
			g[v].push_back(gr[v][i]);
			dfs(gr[v][i]);
		}
	}
}

int t[4 * maxN];
int add[4 * maxN];

void update(int i, int l, int r, int cl, int cr, int value) {
	if (cl > cr) {
		return;
	}
	if (l == cl && r == cr) {
		t[i] += value;
		add[i] += value;
		return;
	}
	if (cl > (l + r) / 2) {
		update(2 * i + 1, (l + r) / 2 + 1, r, cl, cr, value);
	} else if (cr <= (l + r) / 2) {
		update(2 * i, l, (l + r) / 2, cl, cr, value);
	} else {
		update(2 * i, l, (l + r) / 2, cl, (l + r) / 2, value);
		update(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr, value);
	}
	t[i] = min(t[2 * i], t[2 * i + 1]) + add[i];
}

void dfs2(int v, int id, int value = 1000000000, bool adding = true) {
	used[v] = id;
	if (adding) {
		update(1, 1, k, 1, min(value, cnt[v]), +1);
	} else {
		update(1, 1, k, 1, min(value, cnt[v]), -1);
	}
	for (int i = 0; i < g[v].size(); ++i) {
		if (used[g[v][i]] == id) {
			continue;
		}
		dfs2(g[v][i], id, min(value, cnt[v]), adding);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &h[i]);
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	dfs(1);

	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &a[i]);
	}

	sort(a, a + m);
	reverse(a, a + m);
	set < pair < int, int > > S;
	S.insert(make_pair(-h[1], 1));
	int index = -1;
	for (int i = 0; i < m; ++i) {
		pair < int, int > x = *S.begin();
		if (-x.first >= a[i]) {
			S.erase(S.begin());
			for (int j = 0; j < g[x.second].size(); ++j) {
				int v = g[x.second][j];
				S.insert(make_pair(-min(-x.first, h[v]), v));			
			}
		} else {
			index = i;
			break;
		}
	}
	if (index == -1) {
		printf("0\n");
		return 0;
	}

	int value = a[index];
	for (int i = index; i < m; ++i) {
		b[i - index] = a[i];
	}
	k = (m - index);
	reverse(b, b + k);
	for (int i = 1; i <= n; ++i) {
		int pos = upper_bound(b, b + k, h[i]) - b;
		cnt[i] = pos;
	}

	vector < int > head;
	for (set < pair < int, int > > ::iterator it = S.begin(); it != S.end(); ++it) {
		head.push_back(it->second);
	}

	for (int i = 1; i <= k; ++i) {
		update(1, 1, k, i, i, - (k + 1 - i));
	}

	int res = 2000000000;

	int id = 3;
	for (int i = 0; i < head.size(); ++i) {
		dfs2(head[i], id);
	}

	for (int i = 0; i < head.size(); ++i) {
		if (value - h[head[i]] >= res) {
			continue;
		}
		++id;
		dfs2(head[i], id, k, false);
		int oldCnt = cnt[head[i]];
		cnt[head[i]] = k;
		++id;
		dfs2(head[i], id, k, true);
		if (t[1] >= 0) {
			res = value - h[head[i]];
		}
		++id;
		dfs2(head[i], id, k, false);
		cnt[head[i]] = oldCnt;
		++id;
		dfs2(head[i], id, k, true);
	}

	if (res == 2000000000) {
		res = -1;
	}
	printf("%d\n", res);



	return 0;
}