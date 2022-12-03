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
double INF = FLT_MAX;

int main() {
	int n, k; cin >> n >> k;
	vector<ll> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	ll lb = -1, ub = INT_MAX;
	while (ub - lb > 1) {
		ll mid = (lb + ub) / 2;
		vector<int> dp(n, INT_MAX);
		int mi = INT_MAX;
		for (int i = 0; i < n; i++) {
			dp[i] = min(dp[i], i);
			for (int j = i + 1; j < n; j++)
				if ((abs(a[j] - a[i]) + j - i - 1) / (j - i) <= mid)
					dp[j] = min(dp[j], dp[i] + j - i - 1);
			mi = min(mi, dp[i] + n - 1 - i);
		}
		if (mi <= k) ub = mid;
		else lb = mid;
	}
	cout << ub << endl;
}