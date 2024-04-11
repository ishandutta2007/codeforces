
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
#define int long long
const int N = (int) 1e6 + 6, mod = (int) 0;
int dp[N], a[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	int n, m, k, res = 0;
	cin >> n >> m >> k;
	for (int j = 0; j < n; ++j) cin >> a[j];
	for (int r = 1; r <= n; ++r) {
		int sum = 0;
		for (int l = r - 1; l >= max(0LL, r - m); --l) {
			sum += a[l];
			dp[r] = max(dp[r], dp[l] - k + sum); 
		}
		res = max(res, dp[r]);
	}
	cout << res << endl;
}