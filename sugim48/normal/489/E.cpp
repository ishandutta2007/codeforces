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
	int n, l; cin >> n >> l;
	vector<int> x(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) cin >> x[i] >> b[i];
	double lb = 0, ub = 2000;
	for (int k = 0; k < 70; k++) {
		double mid = (lb + ub) / 2;
		vector<double> dp(n + 1, DBL_MAX / 2);
		dp[0] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < i; j++) {
				double f = sqrt((double)abs(x[i] - x[j] - l));
				dp[i] = min(dp[i], dp[j] + f - mid * b[i]);
			}
		if (dp[n] <= 0) ub = mid;
		else lb = mid;
	}
	vector<double> dp(n + 1, DBL_MAX / 2);
	vector<int> prev(n + 1);
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < i; j++) {
			double f = sqrt((double)abs(x[i] - x[j] - l));
			double z = dp[j] + f - lb * b[i];
			if (z < dp[i]) {
				dp[i] = z;
				prev[i] = j;
			}
		}
	vector<int> ans;
	for (int i = n; i > 0; i = prev[i])
		ans.push_back(i);
	reverse(ans.begin(), ans.end());
	for (int k = 0; k < ans.size(); k++)
		cout << ans[k] << ' ';
	cout << endl;
}