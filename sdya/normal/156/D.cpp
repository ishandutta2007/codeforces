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

const int maxN = 110000;
vector < int > g[maxN];
int n, m, k;

bool used[maxN];

void dfs(int v, int &cnt) {
	used[v] = true;
	++cnt;
	for (int i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i]]) {
			dfs(g[v][i], cnt);
		}
	}
}

long long powmod(long long a, long long n) {
	if (n == 0) {
		return 1 % k;
	}

	long long b = powmod(a, n / 2);
	b = (b * b) % (long long)(k);
	if (n % 2 == 1) {
		b = (b * a) % (long long)(k);
	}
	return b;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector < int > c;
	for (int i = 1; i <= n; ++i) {
		int cnt = 0;
		if (!used[i]) {
			dfs(i, cnt);
			c.push_back(cnt);
		}
	}

	long long p = 1LL % (long long)(k), s = 0;
	for (int i = 0; i < c.size(); ++i) {
		p *= (long long)(c[i]);
		p %= (long long)(k);
		s += (long long)(c[i]);
		s %= (long long)(k);
	}
	if (c.size() == 1) {
		cout << (1 % k) << endl;
	} else {
		s = powmod(s, (long long)(c.size()) - 2LL);
		p *= s;
		p %= (long long)(k);
		cout << p << endl;
	}

	return 0;
}