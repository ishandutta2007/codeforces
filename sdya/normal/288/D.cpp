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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 90000;
vector < int > g[maxN];
long long s[maxN], d[maxN], c[maxN];
int n;
long long N;
bool used[maxN];

void rec(int v) {
	used[v] = true;
	vector < int > children;
	s[v] = 1;
	for (int i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i]]) {
			rec(g[v][i]);
			children.push_back(g[v][i]);
			s[v] += s[g[v][i]];
		}
	}

	long long S = 0;
	vector < long long > p(children.size());
	for (int i = 0; i < children.size(); ++i) {
		int u = children[i];
		p[i] = (s[u] * (s[u] - 1)) / 2LL;
		S += p[i];
	}

	for (int i = 0; i < children.size(); ++i) {
		int u = children[i];
		d[v] += p[i] * (S - p[i]);
		d[v] += d[u];

		d[v] += c[u] * (s[v] - s[u]);
		d[v] += 2LL * s[u] * (S - p[i]);
	}

	long long add = (s[v] - 1LL) * (s[v] - 1LL);
	for (int i = 0; i < children.size(); ++i) {
		int u = children[i];
		add -= s[u] * s[u];
	}
	d[v] += add * S;
	for (int i = 0; i < children.size(); ++i) {
		int u = children[i];
		d[v] -= 2LL * s[u] * p[i] * (s[v] - 1LL - s[u]);
	}

	for (int i = 0; i < children.size(); ++i) {
		int u = children[i];
		c[v] += c[u];
		c[v] += 2LL * s[u] * (S - p[i]);
		c[v] += 2LL * p[i];
	}
}

vector < int > getPath(int u, int v) {
	vector < int > p(n + 1, -1);
	queue < int > q;
	q.push(u);
	p[u] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int i = 0; i < g[v].size(); ++i) {
			int u = g[v][i];
			if (p[u] == -1) {
				p[u] = v;
				q.push(u);
			}
		}
	}

	vector < int > res;
	int w = v;
	while (w != 0) {
		res.push_back(w);
		w = p[w];
	}
	return res;
}

void trivial() {
	int res = 0;
	vector < int > used(n + 1, 0);
	int q = 0;
	for (int a = 1; a <= n; ++a) {
		for (int b = a + 1; b <= n; ++b) {
			for (int c = 1; c <= n; ++c) {
				for (int d = c + 1; d <= n; ++d) {
					vector < int > x = getPath(a, b);
					vector < int > y = getPath(c, d);
					++q;
					for (int j = 0; j < x.size(); ++j) {
						used[x[j]] = q;
					}
					bool ok = true;
					for (int j = 0; j < y.size(); ++j) {
						if (used[y[j]] == q) {
							ok = false;
						}
					}
					if (ok) {
						++res;
					}
				}
			}
		}
	}
	cout << res << endl;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	N = n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	rec(1);
	printf("%I64d\n", d[1]);

	//trivial();


	return 0;
}