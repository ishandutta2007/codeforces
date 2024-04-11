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

const int maxN = 110;
const long long inf = 1000000000000000000LL;
int n, d;
int a[maxN];
int x[maxN], y[maxN];
long long g[maxN][maxN];
long long dp[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> d;
	for (int i = 2; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i != j) {
				g[i][j] = (abs(x[i] - x[j]) + abs(y[i] - y[j])) * d - a[j];
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		dp[i] = inf;
	}

	dp[n] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				long long value = max(0LL, dp[j] + g[j][k]);
				if (value < dp[k]) {
					dp[k] = value;
				}
			}
		}
	}
	cout << dp[1] << endl;
	return 0;
}