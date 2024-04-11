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

const int maxN = 310000;
const int maxK = 5100;
const long long inf = 1000000000000000000LL;
int n, k, a[maxN];
long long dp[2][maxK];

void setInf(long long d[]) {
	for (int i = 0; i <= k; ++i) {
		d[i] = inf;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int m1 = (n / k);
	int m2 = m1 + 1;

	{
		int u = 0, v = 1;
		setInf(dp[u]);
		dp[u][0] = 0;
		for (int step = 0; step < k; ++step, swap(u, v)) {
			setInf(dp[v]);
			int total = step * m1;
			for (int i = 0; i <= k; ++i, ++total) {
				if (total + m1 <= n) {
					dp[v][i] = min(dp[v][i], dp[u][i] + (long long)(a[total + m1 - 1] - a[total]));
				}
				if (total + m2 <= n && i + 1 <= k) {
					dp[v][i + 1] = min(dp[v][i + 1], dp[u][i] + (long long)(a[total + m2 - 1] - a[total]));
				}
			}
		}
		cout << dp[u][n % k] << endl;
	}

	//cerr << clock() << endl;
	return 0;
}