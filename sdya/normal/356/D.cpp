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

const int maxN = 71000;

bitset < maxN > c[2], d[2];
int n, s;
int a[maxN], b[maxN];
int v[maxN], cnt;

int fill(bitset < maxN > d[2], int l, int r, int s) {
	int u = 0, v = 1;
	d[u].reset();
	d[u][0] = 1;
	for (int i = l; i <= r; ++i) {
		if (b[i] > s) {
			continue;
		}
		d[v] = (d[u] | (d[u] << b[i]));
		swap(u, v);
	}
	return u;
}

void get(int l, int r, int s) {
	if (s <= 0 || l > r) {
		return;
	}
	if (l == r) {
		v[cnt++] = b[l];
		return;
	}

	int m = (l + r) / 2;
	int x = fill(c, l, m, s);
	int y = fill(d, m + 1, r, s);

	for (int i = 0; i <= s; ++i) {
		if (c[x][i] && d[y][s - i]) {
			get(l, m, i);
			get(m + 1, r, s - i);
			break;
		}
	}
	return;
}

vector < int > used[maxN];
int w[maxN];
vector < int > children[maxN];

void gen() {
	int n = 70000, s = 70000;
	printf("%d %d\n", n, s);
	for (int i = 0; i < n; ++i) {
		printf("%d\n", 1);
	}
}

vector < int > trivial(int s) {
	vector < int > a;
	for (int i = 0; i < n - 1; ++i) {
		a.push_back(b[i]);
	}
	sort(a.rbegin(), a.rend());
	vector < int > res;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] <= s) {
			res.push_back(a[i]);
			s -= a[i];
		}
	}
	if (s == 0) {
		return res;
	}
	return vector < int > ();
}

int dp[210][maxN];

vector < int > trivial2(int s) {
	if (n < 100) {
		return vector < int > ();
	}
	int value = *max_element(b, b + n - 1);
	if (value > 200) {
		return vector < int > ();
	}
	vector < int > cnt(205);
	for (int i = 0; i < n - 1; ++i) {
		++cnt[b[i]];
	}

	const int inf = 1000000000;
	for (int i = 0; i < 210; ++i) {
		for (int j = 0; j <= s; ++j) {
			dp[i][j] = inf;
		}
	}
	dp[0][0] = 0;
	for (int i = 1; i < 205; ++i) {
		for (int j = 0; j <= s; ++j) {
			if (dp[i - 1][j] < inf) {
				dp[i][j] = min(dp[i][j], 0);
			}
			if (j >= i && dp[i][j - i] < cnt[i]) {
				dp[i][j] = min(dp[i][j], dp[i][j - i] + 1);
			}
		}
	}
	if (dp[204][s] == inf) {
		printf("-1\n");
		exit(0);
	}

	int u = 204, v = s;
	vector < int > res;
	while (u) {
		for (int i = 0; i < dp[u][v]; ++i) {
			res.push_back(u);
		}
		v -= u * dp[u][v];
		--u;
	}
	return res;
}

void build(int value) {
	set < int > S;
	for (int i = 0; i < cnt; ++i) {
		int index = used[v[i]].back();
		S.insert(index);
		used[v[i]].pop_back();
		v[i] = index;
	}
	int id = used[value].back();
	S.insert(used[value].back());
	used[value].pop_back();

	vector < int > current;
	current.push_back(id);
	for (int i = maxN - 1; i >= 0; --i) {
		for (int j = 0; j < used[i].size(); ++j) {
			current.push_back(used[i][j]);
		}
	}

	for (int i = 0; i + 1 < current.size(); ++i) {
		w[current[i]] = a[current[i]] - a[current[i + 1]];
		children[current[i]].push_back(current[i + 1]);
	}

	for (int i = 0; i < n; ++i) {
		printf("%d", w[i]);
		printf(" %d", children[i].size());
		for (int j = 0; j < children[i].size(); ++j) {
			printf(" %d", children[i][j] + 1);
		}
		printf("\n");
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//gen();
	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		b[i] = a[i];
		used[a[i]].push_back(i);
		w[i] = a[i];
	}
	sort(b, b + n);
	int value = b[n - 1];
	s -= value;
	random_shuffle(b, b + n - 1);

	vector < int > cur = trivial(s);
	if (cur.size() > 0) {
		for (int i = 0; i < cur.size(); ++i) {
			v[i] = cur[i];
		}
		cnt = cur.size();
		build(value);
		return 0;
	}
	cur = trivial2(s);
	if (cur.size() > 0) {
		for (int i = 0; i < cur.size(); ++i) {
			v[i] = cur[i];
		}
		cnt = cur.size();
		build(value);
		return 0;
	}
	get(0, n - 2, s);
	int sum = 0;
	for (int i = 0; i < cnt; ++i) {
		sum += v[i];
	}
	if (s != sum) {
		printf("-1\n");
		return 0;
	}
	build(value);
	
	cerr << clock() << endl;

	return 0;
}