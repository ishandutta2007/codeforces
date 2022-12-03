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
#include <random>
#include <unordered_map>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

int const MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-12;
int INF = INT_MAX / 10;

bool f(int a, int b, int h, int w) {
	if (a <= h && b <= w) return true;
	if (b <= h && a <= w) return true;
	return false;
}

int main() {
	int a, b, h, w, N;
	cin >> a >> b >> h >> w >> N;
	if (f(a, b, h, w)) {
		cout << 0 << endl;
		return 0;
	}
	vector<int> c(N);
	rep(i, N) scanf("%d", &c[i]);
	sort(c.rbegin(), c.rend());
	vector<int> dp(100001);
	dp[h] = w;
	rep(i, N) {
		vector<int> _dp(100001);
		for (int x = 1; x <= 100000; x++) {
			_dp[x] = max(_dp[x], (int)min(100000LL, (ll)dp[x] * c[i]));
			int _x = min(100000LL, (ll)x * c[i]);
			_dp[_x] = max(_dp[_x], dp[x]);
		}
		dp = _dp;
		for (int x = 1; x <= 100000; x++)
			if (f(a, b, x, dp[x])) {
				cout << i + 1 << endl;
				return 0;
			}
	}
	cout << -1 << endl;
}