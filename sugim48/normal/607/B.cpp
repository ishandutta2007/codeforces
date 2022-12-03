#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<vector<int> > dp(n + 1, vector<int>(n + 1, 1));
	for (int d = 2; d <= n; d++)
		for (int l = 0; l + d <= n; l++) {
			int r = l + d;
			dp[l][r] = INT_MAX;
			for (int m = l + 1; m <= r - 1; m++)
				dp[l][r] = min(dp[l][r], dp[l][m] + dp[m][r]);
			if (a[l] == a[r - 1])
				dp[l][r] = min(dp[l][r], dp[l + 1][r - 1]);
		}
	cout << dp[0][n] << endl;
}