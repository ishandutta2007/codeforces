#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<vector>
#include<set>
#include<algorithm>
#include<iostream>
#include<ctime>
#include<iomanip>
#include<cassert>
#include<memory>
#include<string>
#include<string.h>
#include<math.h>

using namespace std;

typedef double ld;
typedef long long li;
typedef pair<int, int> pt;

const int T = 5005;
const int N = 55;

int n, t;
int f[N], s[N], p[N];

void read() {
	cin >> n >> t;
	for (int i = 0; i < n; ++i)
		cin >> f[i] >> s[i] >> p[i];
}

ld dp[N][T];

bool ok(ld mid) {
	for (int j = 0; j < T; ++j)
		dp[n][j] = j <= t ? 0 : mid;
	for (int i = n - 1; i >= 0; --i)
		for (int j = 0; j < T - s[i] - 1; ++j) {
			dp[i][j] = mid;
			dp[i][j] = min(dp[i][j], (p[i] * (f[i] + dp[i + 1][j + f[i]]) + (100 - p[i]) * (s[i] + dp[i + 1][j + s[i]])) / 100);
		}
	return dp[0][0] < mid;
}

void solve() {
	ld l = 0, r = 1e9;
	for (int i = 0; i < 100; ++i) {
		ld mid = (l + r) / 2;
		if (ok(mid))
			r = mid;
		else
			l = mid;
	}
	cout << setprecision(10) << r << endl;
}

int main() {

	srand(time(NULL));

	read();
	solve();

	return 0;
}