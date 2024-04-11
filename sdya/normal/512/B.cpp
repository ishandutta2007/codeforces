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

int gcd(int a, int b) {
	if (a == 0 || b == 0) {
		return a + b;
	}
	if (a > b) {
		return gcd(a % b, b);
	} else {
		return gcd(b % a, a);
	}
}

const int maxN = 400;
const long long inf = 1000000000000000000LL;
int n, l[maxN], c[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> l[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}

	vector < int > d;
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j * j <= l[i]; ++j) {
			if (l[i] % j == 0) {
				d.push_back(j);
				d.push_back(l[i] / j);
			}
		}
	}
	sort(d.begin(), d.end());
	d.resize(unique(d.begin(), d.end()) - d.begin());
	int m = d.size();
	int u = 0, v = 1;
	vector < vector < long long > > dp(2, vector < long long > (m, inf));

	for (int i = 0; i < n; ++i, swap(u, v)) {
		dp[v].assign(m, inf);
		for (int j = 0; j < m; ++j) {
			if (dp[u][j] == inf) {
				continue;
			}
			dp[v][j] = min(dp[v][j], dp[u][j]);
			int value = gcd(d[j], l[i]);
			int index = lower_bound(d.begin(), d.end(), value) - d.begin();
			dp[v][index] = min(dp[v][index], dp[u][j] + (long long)(c[i]));
		}
		int index = lower_bound(d.begin(), d.end(), l[i]) - d.begin();
		dp[v][index] = min(dp[v][index], (long long)(c[i]));
	}

	if (dp[u][0] == inf) {
		cout << -1 << endl;
	} else {
		cout << dp[u][0] << endl;
	}

	return 0;
}