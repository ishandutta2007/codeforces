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
#include <cassert>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<int, ll> i_ll;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int v; ll w; };

const int MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;
ll INF = LLONG_MAX / 3;

int main() {
	int N; cin >> N;
	vector<ll> a(N);
	rep(i, N) scanf("%lld", &a[i]);
	vector<ll> da(N - 1);
	rep(i, N - 1) {
		da[i] = abs(a[i + 1] - a[i]);
		if (i % 2) da[i] *= -1;
	}
	vector<ll> sum(N);
	rep(i, N - 1) sum[i + 1] = sum[i] + da[i];
	ll mi = LLONG_MAX, ma = LLONG_MIN;
	ll ans = 0;
	for (int i = N - 1; i >= 0; i--) {
		ll x = sum[i];
		mi = min(mi, x);
		ma = max(ma, x);
		if (i % 2 == 0) ans = max(ans, ma - x);
		else ans = max(ans, x - mi);
	}
	cout << ans << endl;
}