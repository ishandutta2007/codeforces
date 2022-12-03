#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <fstream>
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
struct edge { int v, w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int n, m, b, mod;
	cin >> n >> m >> b >> mod;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<vector<int> > dp(m + 1, vector<int>(b + 1));
	dp[0][0] = 1 % mod;
	for (int i = 0; i < n; i++)
		for (int j = 0; j + 1 <= m; j++)
			for (int k = 0; k + a[i] <= b; k++) {
				dp[j + 1][k + a[i]] += dp[j][k];
				if (dp[j + 1][k + a[i]] >= mod)
					dp[j + 1][k + a[i]] -= mod;
			}
	int ans = 0;
	for (int k = 0; k <= b; k++)
		ans = (ans + dp[m][k]) % mod;
	cout << ans << endl;
}