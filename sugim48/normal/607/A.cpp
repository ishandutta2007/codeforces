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
	vector<i_i> ab(n);
	for (int i = 0; i < n; i++)
		cin >> ab[i].first >> ab[i].second;
	sort(ab.begin(), ab.end());
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		a[i] = ab[i].first;
		b[i] = ab[i].second;
	}
	vector<int> dp(n + 1);
	for (int i = 0; i < n; i++) {
		int j = lower_bound(a.begin(), a.end(), a[i] - b[i]) - a.begin();
		dp[i + 1] = dp[j] + 1;
	}
	int ma = 0;
	for (int i = 0; i <= n; i++)
		ma = max(ma, dp[i]);
	cout << n - ma << endl;
}