#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110;
long long a[maxN][maxN], b[maxN][maxN];
long long c[maxN];
vector < long long > candidates[maxN];
int n, m;

long long gcd(long long x, long long y) {
	if (x == 0 || y == 0) {
		return x + y;
	}
	if (x > y) {
		return gcd(x % y, y);
	} else {
		return gcd(y % x, x);
	}
}

long long lcm(long long x, long long y) {
	return x / gcd(x, y) * y;
}

bool check() {
	for (int i = 1; i <= n; ++i) {
		if (c[i] > 1000000) {
			return false;
		}
		for (int j = 1; j <= n; ++j) {
			if (a[i][j] != 0 && b[i][j] % lcm(c[i], c[j]) != 0) {
				return false;
			}
			if (a[i][j] != 0 && a[i][j] % gcd(c[i], c[j]) != 0) {
				return false;
			}
		}
	}
	return true;
}

bool used[maxN];
long long d[maxN];

bool isCorrect() {
	for (int i = 1; i <= n; ++i) {
		if (d[i] > 1000000) {
			return false;
		}
		for (int j = 1; j <= n; ++j) {
			if (a[i][j] != 0 && lcm(d[i], d[j]) != b[i][j]) {
				return false;
			}
			if (a[i][j] != 0 && gcd(d[i], d[j]) != a[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void rec(int v, int cnt = 0) {
	if (cnt == n) {
		if (isCorrect()) {
			cout << "YES" << endl;
			for (int i = 1; i <= n; ++i) {
				cout << d[i] << " ";
			}
			cout << endl;
			exit(0);
		} else {
			return;
		}
	}
	for (int i = 0; i < candidates[v].size(); ++i) {
		bool isOk = true;
		long long value = candidates[v][i];
		for (int j = 1; j <= n; ++j) {
			if (a[v][j] != 0 && used[j] && (lcm(value, d[j]) != b[v][j] || gcd(value, d[j]) != a[v][j])) {
				isOk = false;
				break;
			}
		}
		if (isOk) {
			used[v] = true;
			d[v] = value;
			int best = -1, ways = 1000000;
			for (int j = 1; j <= n; ++j) {
				if (a[v][j] != 0 && !used[j] && candidates[j].size() < ways) {
					ways = candidates[j].size();
					best = j;
				}
			}
			if (best == -1) {
				for (int j = 1; j <= n; ++j) {
					if (!used[j]) {
						best = j;
						break;
					}
				}
			}
			rec(best, cnt + 1);
			used[v] = false;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		c[i] = 1;
	}
	for (int i = 0; i < m; ++i) {
		int u, v, x, y;
		cin >> u >> v >> x >> y;
		a[u][v] = a[v][u] = x;
		b[u][v] = b[v][u] = y;
		c[u] = lcm(c[u], x);
		c[v] = lcm(c[v], x);
		if (c[u] > 1000000) {
			cout << "NO" << endl;
			return 0;
		}
		if (c[v] > 1000000) {
			cout << "NO" << endl;
			return 0;
		}
	}

	if (!check()) {
		cout << "NO" << endl;
		return 0;
	}

	for (int i = 1; i <= n; ++i) {
		long long r = 0;
		for (int j = 1; j <= n; ++j) {
			if (a[i][j] != 0) {
				r = gcd(r, b[i][j]);
			}
		}
		if (r == 0) {
			r = 1;
		}
		if (r < c[i]) {
			cout << "NO" << endl;
			return 0;
		}
		if (r != 0) {
			for (int j = 1; j * j <= r; ++j) {
				if (r % j == 0) {
					long long A = j;
					long long B = r / j;
					if (A <= 1000000LL && A % c[i] == 0) {
						candidates[i].push_back(A);
					}
					if (B <= 1000000LL && B % c[i] == 0) {
						candidates[i].push_back(B);
					}
				}
			}
			sort(candidates[i].begin(), candidates[i].end());
			candidates[i].resize(unique(candidates[i].begin(), candidates[i].end()) - candidates[i].begin());
		} else {
			candidates[i].push_back(c[i]);
		}
	}

	rec(1);
	cout << "NO" << endl;

	return 0;
}