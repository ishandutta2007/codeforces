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

int INF = INT_MAX / 2;
ll MOD = 1234576891234601LL;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int n, m; cin >> n >> m;
	vector<int> a(m);
	while (n--) {
		int x; scanf("%d", &x);
		a[x % m]++;
	}
	vector<bool> dp(m);
	for (int x = 0; x < m; x++)
		for (int k = 1; a[x]; k *= 2) {
			int n = min(a[x], k);
			a[x] -= n;
			int y = x * n % m;
			vector<bool> _dp = dp;
			_dp[y] = true;
			for (int z = 0; z < m; z++)
				if (dp[z])
					_dp[(z + y) % m] = true;
			dp = _dp;
		}
	cout << (dp[0] ? "YES" : "NO") << endl;
}