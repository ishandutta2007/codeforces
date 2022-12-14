
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

const int N = (int) 85, K = 11, mod = (int) 0;
int dp[N][K], mat[N][N], par[N];
int main() {
	srand(time(0));
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> mat[i][j];
		}
	}
	int res = 2e9;
	for (int turn = 0; turn < 3000; ++turn) {
		memset(dp, 63, sizeof dp);
		for (int i = 0; i < n; ++i) par[i] = rand() & 1;
		dp[0][0] = 0;
		for (int s = 1; s <= k; ++s) {
			for (int i = 0; i < n; ++i) {
				for (int t = 0; t < n; ++t) if (par[i] != par[t]) {
					dp[t][s] = min(dp[t][s], dp[i][s-1] + mat[i][t]);
				}
			}
		}
		res = min(res, dp[0][k]);
	}
	cout << res << endl;
}