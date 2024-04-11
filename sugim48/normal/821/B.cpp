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

const int MOD = 1e9 + 7;
double EPS = 1e-10;

int main() {
	ll m, b; cin >> m >> b;
	ll ma = 0;
	for (ll y = 0; y <= b; y++) {
		ll x = m * (b - y);
		ll ans = y * (y + 1) / 2 * (x + 1);
		ans += x * (x + 1) / 2 * (y + 1);
		ma = max(ma, ans);
	}
	cout << ma << endl;
}