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

const int maxN = 5100;
int dp[maxN], n;
long long a[maxN];
int p[maxN];

bool can(int i, int j) {
	int x = p[i];
	int y = p[j] - (j - i - 1);
	if (y < 0) {
		y = 0;
	}
	return ((x == y - 1 && y > 0) || y == 0) && a[i] % a[j] == 0;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		while (a[i] % 2 == 0) {
			a[i] /= 2;
			++p[i];
		}
	}

	for (int i = 1; i <= n; ++i) {
		dp[i] = i - 1;
		for (int j = 1; j < i; ++j) {
			if (can(j, i)) {
				dp[i] = min(dp[i], dp[j] + i - j - 1);
			}
		}
	}
	int res = n - 1;
	for (int i = 1; i <= n; ++i) {
		res = min(res, dp[i] + n - i);
	}

	cout << res << endl;


	return 0;
}