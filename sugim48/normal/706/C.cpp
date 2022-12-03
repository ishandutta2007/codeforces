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
#include <list>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<int, ll> i_ll;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 10007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int N; cin >> N;
	vector<int> a(N);
	for (int& x: a) scanf("%d", &x);
	vector<string> s(N), t(N);
	for (int i = 0; i < N; i++) {
		cin >> s[i];
		t[i] = s[i];
		reverse(t[i].begin(), t[i].end());
	}
	ll x = 0, y = a[0];
	for (int i = 0; i + 1 < N; i++) {
		ll _x = LLONG_MAX / 2, _y = LLONG_MAX / 2;
		if (s[i] <= s[i + 1]) _x = min(_x, x);
		if (s[i] <= t[i + 1]) _y = min(_y, x + a[i + 1]);
		if (t[i] <= s[i + 1]) _x = min(_x, y);
		if (t[i] <= t[i + 1]) _y = min(_y, y + a[i + 1]);
		x = _x; y = _y;
	}
	ll ans = min(x, y);
	if (ans == LLONG_MAX / 2) ans = -1;
	cout << ans << endl;
}