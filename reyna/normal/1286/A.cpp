
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;

const int N = (int) 105, mod = (int) 0;
int m, p[N], unused[N], dp[N][2], odp[N][2];
int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cin >> p[j], --p[j];
		if (p[j] >= 0)
			unused[p[j]] = 1;
	}
	for (int j = 0; j < n; ++j)
		m += (j & 1);
	memset(dp, 63, sizeof dp);
	dp[0][0] = dp[0][1] = 0;
	for (int cur = 0; cur < n; ++cur) {
		memcpy(odp, dp, sizeof dp);
		memset(dp, 63, sizeof dp);
		for (int lodd = 0; lodd <= n; ++lodd) {
			for (int parity = 0; parity <= 1; ++parity) {
				for (int last = 0; last <= 1; ++ last) {
					if (p[cur] >= 0 && (p[cur] & 1) != parity) continue;
					dp[lodd + parity][parity] = min(dp[lodd + parity][parity], odp[lodd][last] + (last != parity));
				}
			}
		}
	}
	cout << min(dp[m][0], dp[m][1]) << endl;
	
}