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

const int N = (int) 1e6 + 6, mod = (int) 0;
int dp[N], a[N];
vector<int> all[N];
int main() {
	int q;
	cin >> q;
	memset(dp, -63, sizeof dp);
	while (q--) {
		int n, cnt = 0;
		cin >> n;
		for (int j = 0; j < n; ++j) {
			cin >> a[j];
			--a[j];
			all[a[j]].pb(j);
		}
		int last = n;
		dp[n] = 0;
		for (int r = n - 1; r >= 0; --r) {
			cnt += !!((int) all[r].size());
			dp[r] = dp[r + 1];
			if ((int) all[r].size()) {
				if (all[r].back() < last) {
					dp[r] = dp[r + 1] + 1;	
				} else {
					dp[r] = 1;
				}
				last = all[r][0];
			}
		}
		int res = 0;
		for (int j = 0; j <= n; ++j) res = max(res, dp[j]);
		cout << cnt - res << '\n';
		for (int j = 0; j <= n; ++j) dp[j] = -1e9, all[j].clear();
	}
}