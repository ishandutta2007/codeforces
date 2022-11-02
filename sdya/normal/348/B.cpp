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

const int maxN = 110000;
const long long inf = 1000000000000000000LL;
int n, a[maxN];
vector < int > g[maxN];
pair < int, int > d[maxN];

long long mul(long long a, long long b) {
	if (a > inf / b) {
		return inf;
	}
	return a * b;
}

long long gcd(long long a, long long b) {
	if (a == 0 || b == 0) {
		return a + b;
	}
	if (a > b) {
		return gcd(a % b, b);
	}
	return gcd(b % a, a);
}

long long lcm(long long a, long long b) {
	long long g = a / gcd(a, b);
	return mul(g, b);
}

long long dfs(int v, int parent = -1, long long d = 1) {
	int cnt = 0;
	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i] != parent) {
			++cnt;
		}
	}

	long long res = d;
	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i] != parent) {
			res = lcm(res, dfs(g[v][i], v, mul(d, cnt)));
		}
	}
	return res;
}

bool check(int v, int parent, long long total) {
	int cnt = 0;
	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i] != parent) {
			++cnt;
		}
	}

	if (cnt == 0) {
		if (total > a[v]) {
			return false;
		}
		return true;
	}

	if (total % cnt != 0) {
		cerr << "Fuck" << endl;
	}

	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i] != parent) {
			if (!check(g[v][i], v, total / (long long)(cnt))) {
				return false;
			}
		}
	}
	return true;
}

bool check(long long total) {
	return check(1, -1, total);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	long long total = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		total += (long long)(a[i]);
	}

	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	long long t = dfs(1);
	if (t > total) {
		cout << total << endl;
		return 0;
	}

	long long left_bound = 0, right_bound = (total - (total % t)) / t;
	while (right_bound - left_bound > 1) {
		long long middle = (left_bound + right_bound) / 2;
		if (check(middle * t)) {
			left_bound = middle;
		} else {
			right_bound = middle;
		}
	}

	if (check(right_bound * t)) {
		cout << total - t * right_bound << endl;
	} else {
		cout << total - t * left_bound << endl;
	}



	return 0;
}