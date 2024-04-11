#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstring>
#include <ctime>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; double w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int n; cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) scanf("%I64d", &a[i]);
	int c1 = 0, c2 = 0; ll s1 = 0, s2 = 0;
	for (int i = 1; i < n - 1; i++) {
		if ((a[i] - a[i - 1]) * (a[i + 1] - a[i]) > 0) continue;
		ll x1 = s2, x2 = s2;
		if (c1 <= i - 1) x1 = max(x1, s1 + abs(a[i - 1] - a[c1]));
		if (c2 <= i - 1) x1 = max(x1, s2 + abs(a[i - 1] - a[c2]));
		if (c1 <= i) x2 = max(x2, s1 + abs(a[i] - a[c1]));
		if (c2 <= i) x2 = max(x2, s2 + abs(a[i] - a[c2]));
		c1 = i; c2 = i + 1; s1 = x1; s2 = x2;
	}
	ll ans = max(s1 + abs(a[n - 1] - a[c1]), s2 + abs(a[n - 1] - a[c2]));
	cout << ans << endl;
}