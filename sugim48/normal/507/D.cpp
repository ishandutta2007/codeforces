#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
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
struct edge { int v, w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int n, k; int m;
	cin >> n >> k >> m;
	vector<ll> a(n + 1);
	a[0] = 1 % m;
	for (int i = 1; i <= n; i++)
		a[i] = a[i - 1] * 10 % m;
	vector< vector<ll> > dp(n + 1, vector<ll>(k));
	dp[0][0] = 1 % m;
	int y = 1 % k;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int x = 0; x < 10; x++)
			for (int j = 0; j < k; j++)
				dp[i][(j + y * x) % k] = (dp[i][(j + y * x) % k] + dp[i - 1][j]) % m;
		if (i == n) ans = (ans + dp[i][0] - 1) % m;
		else {
			ans = (ans + (dp[i][0] - 1) * a[n - i - 1] * 9) % m;
			dp[i][0] = 1;
		}
		y = y * 10 % k;
	}
	ans = (ans % m + m) % m;
	cout << ans << endl;
}