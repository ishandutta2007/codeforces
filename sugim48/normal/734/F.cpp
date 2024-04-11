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
	ll N; cin >> N;
	vector<ll> b(N), c(N);
	rep(i, N) scanf("%lld", &b[i]);
	rep(i, N) scanf("%lld", &c[i]);
	vector<ll> d(N);
	rep(i, N) d[i] = b[i] + c[i];
	ll D = 0;
	rep(i, N) D += d[i];
	if (D % (N * 2)) {
		cout << -1 << endl;
		return 0;
	}
	ll A = D / (N * 2);
	vector<ll> a(N);
	rep(i, N) {
		if (d[i] - A < 0 || (d[i] - A) % N) {
			cout << -1 << endl;
			return 0;
		}
		a[i] = (d[i] - A) / N;
	}
	vector<ll> unko(35), mazai(35);
	rep(i, N) rep(k, 35) {
		unko[k] += a[i] & (1LL<<k);
		mazai[k] += 1LL<<k;
	}
	rep(i, N) {
		ll x = 0, y = 0;
		rep(k, 35) {
			x += (a[i]>>k & 1) ? unko[k] : 0;
			y += (a[i]>>k & 1) ? mazai[k] : unko[k];
		}
		if (x != b[i] || y != c[i]) {
			cout << -1 << endl;
			return 0;
		}
	}
	rep(i, N) printf("%lld ", a[i]);
	cout << endl;
}