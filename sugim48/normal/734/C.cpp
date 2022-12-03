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

#define rep(i, N) for (int i = 0; i < N; i++)

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	ll k; int N, M;
	cin >> k >> N >> M;
	ll x, s; cin >> x >> s;
	vector<ll> a(N + 1), b(N + 1);
	a[0] = x; b[0] = 0;
	rep(i, N) scanf("%lld", &a[i + 1]);
	rep(i, N) scanf("%lld", &b[i + 1]);
	N++;
	vector<ll> c(M + 1), d(M + 1);
	c[0] = 0; d[0] = 0;
	rep(j, M) scanf("%lld", &c[j + 1]);
	rep(j, M) scanf("%lld", &d[j + 1]);
	M++;
	ll mi = LLONG_MAX;
	rep(i, N) {
		if (b[i] > s) continue;
		int j = upper_bound(d.begin(), d.end(), s - b[i]) - d.begin() - 1;
		mi = min(mi, (k - c[j]) * a[i]);
	}
	cout << mi << endl;
}