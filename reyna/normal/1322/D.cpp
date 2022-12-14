
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
const int N = (int) 6005, mod = (int) 0;
int agr[N], cost[N], prof[N], have[N];
vector<int> dp[N], odp[N];
int32_t main() {
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < n; ++j) cin >> agr[j], --agr[j], have[agr[j]]++;
	for (int j = 0; j < n; ++j) cin >> cost[j];
	for (int j = 0; j < n + m; ++j) cin >> prof[j];
	m += n + 2;
	for (int k = 1; k < m; ++k)
		have[k] += (have[k-1] + 1) / 2;
	for (int k = 0; k < m; ++k)
		dp[k].resize(have[k]+1), odp[k].resize(have[k]+1);
	for (int k = 0; k < m; ++k)
		for (int j = 0; j < have[k]+1; ++j)
			dp[k][j] = -1e18;
	dp[0][0] = 0;
	for (int k = 0; k < m-1; ++k)
		for (int j = 0; j < have[k]+1; ++j)
			dp[k+1][j/2] = max(dp[k+1][j/2], dp[k][j] + prof[k] * j);
	for (int pos = n - 1; pos >= 0; --pos) {
		{
			int k = agr[pos];
			for (int j = have[k]; j >= 1; --j)
				dp[k][j] = max(dp[k][j], dp[k][j-1] - cost[pos]);
		}
		for (int k = 0; k < m-1; ++k)
			for (int j = 0; j < have[k]+1; ++j)
				dp[k+1][j/2] = max(dp[k+1][j/2], dp[k][j] + prof[k] * j);
	}
	cout << dp[m-1][0] << endl;
}