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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 5000;
const int maxD = 100000;
long long n, m;
long long p[maxN];

long long res = 0;

long long dp[110][maxD];

long long rec(int index, long long n) {
	if (index < 0) {
		return n;
	}
	if (n < maxD) {
		if (dp[index][n] != -1) {
			return dp[index][n];
		}
	}
	long long res = n;
	int pos = upper_bound(p, p + m, n) - p;
	for (int i = min(index, pos - 1); i >= 0; --i) {
		res -= rec(i - 1, n / p[i]);
	}
	if (n < maxD) {
		dp[index][n] = res;
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> p[i];
	}
	sort(p, p + m);
	memset(dp, -1, sizeof(dp));
	cout << rec(m - 1, n) << endl;
	
	return 0;
}