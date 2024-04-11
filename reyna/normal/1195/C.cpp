
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
int dp[N][2], a[2][N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i <= 1; ++i)
		for (int j = 0; j < n; ++j)
			cin >> a[i][j];
	for (int j = 0; j < n; ++j) {
		for (int cur = 0; cur <= 1; ++cur) {
			for (int last = 0; last <= 1; ++last) {
				dp[j + 1][cur] = max(dp[j + 1][cur], dp[j][last] + (cur == last ? 0 : a[cur][j]));	
			}
		}
	}
	cout << max(dp[n][0], dp[n][1]) << endl;
}