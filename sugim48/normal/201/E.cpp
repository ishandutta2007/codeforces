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

ll c[100][100];

ll C(ll n, ll k) {
	if (n < 100) return c[n][k];
	ll ans = 1;
	for (int i = 0; i < k; i++)
		ans *= n - i;
	for (int i = 1; i <= k; i++)
		ans /= i;
	return ans;
}

class NumberMagic {
public:
	int theMin(int _N, int _M) {
		if (_N == 1) return 0;
		for (int i = 0; i < 100; i++) {
			c[i][0] = 1;
			for (int j = 1; j <= i; j++)
				c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
		ll N = _N, M = _M;
		ll lb = 0, ub = N - 1;
		while (ub - lb > 1) {
			ll mid = (lb + ub) / 2;
			ll n = N, sum = 0;
			for (ll k = 0; k <= mid && n; k++) {
				ll unko = min(n, C(mid, k));
				n -= unko;
				sum += k * unko;
			}
			if (!n && sum <= mid * M) ub = mid;
			else lb = mid;
		}
		return ub;
	}
};

int main() {
	NumberMagic nm;
	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		cout << nm.theMin(N, M) << endl;
	}
}