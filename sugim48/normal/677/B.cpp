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
struct edge { int v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
ll INF = LLONG_MAX / 3;
double EPS = 1e-10;

int main() {
	int N; ll h, k; cin >> N >> h >> k;
	vector<ll> a(N);
	for (ll& x: a) scanf("%lld", &x);
	a.push_back(h);
	ll z = 0, ans = 0;
	for (ll& x: a) {
		ll t = (x - (h - z) + k - 1) / k;
		z = max(0LL, z - t * k) + x;
		ans += t;
	}
	cout << ans << endl;
}