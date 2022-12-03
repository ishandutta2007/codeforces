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
struct edge { int v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-8;
ll INF = LLONG_MAX / 2;

int main() {
	int n, x; cin >> n >> x;
	vector<int> l(n), r(n);
	for (int i = 0; i < n; i++)
		cin >> l[i] >> r[i];
	vector<int> v;
	v.push_back(x);
	for (int i = 0; i < n; i++) {
		v.push_back(l[i]);
		v.push_back(r[i]);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	int m = v.size();
	x = lower_bound(v.begin(), v.end(), x) - v.begin();
	for (int i = 0; i < n; i++) {
		l[i] = lower_bound(v.begin(), v.end(), l[i]) - v.begin();
		r[i] = lower_bound(v.begin(), v.end(), r[i]) - v.begin();
	}
	vector<ll> dp(m, INF);
	dp[x] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < m; j++)
			dp[j] = min(dp[j], dp[j - 1] + v[j] - v[j - 1]);
		for (int j = m - 2; j >= 0; j--)
			dp[j] = min(dp[j], dp[j + 1] + v[j + 1] - v[j]);
		for (int j = 0; j < m; j++) {
			if (j < l[i]) dp[j] += v[l[i]] - v[j];
			if (j > r[i]) dp[j] += v[j] - v[r[i]];
		}
	}
	ll mini = INF;
	for (int j = 0; j < m; j++)
		mini = min(mini, dp[j]);
	cout << mini << endl;
}