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
typedef pair<int, ll> i_ll;
struct edge { int u, v; ll w; };

ll INF = LLONG_MAX / 2;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int N, a, b, c, d;
	cin >> N >> a >> b >> c >> d;
	ll ans = 0;
	for (int x = 1; x <= N; x++) {
		int lb = INT_MIN, ub = INT_MAX;
		lb = max(lb, a + b + 1); ub = min(ub, a + b + N);
		lb = max(lb, b + d + 1); ub = min(ub, b + d + N);
		lb = max(lb, d + c + 1); ub = min(ub, d + c + N);
		lb = max(lb, c + a + 1); ub = min(ub, c + a + N);
		ans += max(0, ub - lb + 1);
	}
	cout << ans << endl;
}