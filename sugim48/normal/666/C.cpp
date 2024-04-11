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
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

ll extgcd(ll a, ll b, ll& x, ll& y) {
	if (b == 0) {
		x = (a >= 0) ? 1 : -1;
		y = 0;
		return abs(a);
	}
	else {
		ll res = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
		return res;
	}
}

ll mod_inverse(ll a, ll m) {
	ll x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}

ll C(int N, int K, vector<ll>& f, vector<ll>& fi) {
	return (ll)f[N] * fi[K] % MOD * fi[N - K] % MOD;
}

int pow_mod(ll x, ll n, int m) {
	ll res = 1;
	for (; n > 0; n >>= 1) {
		if (n & 1) res = (res * x) % m;
		x = (x * x) % m;
	}
	return res;
}

int main() {
	vector<ll> f(200001), fi(200001);
	f[0] = fi[0] = 1;
	for (int i = 1; i <= 200000; i++) {
		f[i] = (ll)f[i - 1] * i % MOD;
		fi[i] = mod_inverse(f[i], MOD);
	}

	int Q; cin >> Q;
	vector<int> t(Q + 1), x(Q + 1);
	string s; cin >> s;
	t[0] = 1; x[0] = s.length();
	for (int k = 1; k <= Q; k++) {
		scanf("%d", &t[k]);
		if (t[k] == 1) {
			string s; cin >> s;
			x[k] = s.length();
		}
		if (t[k] == 2) scanf("%d", &x[k]);
	}
	Q++;
	vector<int> xs;
	for (int k = 0; k < Q; k++)
		if (t[k] == 1)
			xs.push_back(x[k]);
	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());
	int M = xs.size();
	vector<vector<int> > v(M);
	int j;
	for (int k = 0; k < Q; k++) {
		if (t[k] == 1)
			j = lower_bound(xs.begin(), xs.end(), x[k]) - xs.begin();
		if (t[k] == 2)
			v[j].push_back(k);
	}
	vector<int> ans(Q, -1);
	ll z = (ll)25 * mod_inverse(26, MOD) % MOD;
	for (int j = 0; j < M; j++) {
		int m = xs[j];
		vector<ll> a(100001);
		ll y = 1;
		for (int i = m; i <= 100000; i++) {
			a[i] = (a[i - 1] + C(i - 1, m - 1, f, fi) * y) % MOD;
			y = y * z % MOD;
		}
		for (int k: v[j]) {
			int n = x[k];
			if (n < m) {
				ans[k] = 0;
				continue;
			}
			ans[k] = a[n] * pow_mod(26, n - m, MOD) % MOD;
		}
	}
	for (int x: ans)
		if (x != -1)
			printf("%d\n", x);
}