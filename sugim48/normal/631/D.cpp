#define _USE_MATH_DEFINES
#include <algorithm>
#include <complex>
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
typedef pair<ll, char> ll_c;
struct edge { int v, w; };

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

ll f(int l, int r, vector<ll>& h, vector<ll>& zi) {
	ll x = (h[r] - h[l]) * zi[l] % MOD;
	return (x + MOD) % MOD;
}

int main() {
	int N, M; cin >> N >> M;
	vector<ll_c> a, b;
	while (N--) {
		int l; char c; scanf("%d-%c", &l, &c);
		if (a.size() && a.back().second == c) a.back().first += l;
		else a.push_back(ll_c(l, c));
	}
	while (M--) {
		int l; char c; scanf("%d-%c", &l, &c);
		if (b.size() && b.back().second == c) b.back().first += l;
		else b.push_back(ll_c(l, c));
	}
	N = a.size();
	M = b.size();
	if (M == 1) {
		ll ans = 0;
		for (int i = 0; i < N; i++)
			if (a[i].second == b[0].second)
				ans += max(0LL, a[i].first - b[0].first + 1);
		cout << ans << endl;
		return 0;
	}
	vector<ll_c> v;
	for (ll_c x: a) v.push_back(x);
	for (ll_c x: b) v.push_back(x);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	vector<int> A(N), B(M);
	for (int i = 0; i < N; i++)
		A[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
	for (int j = 0; j < M; j++)
		B[j] = lower_bound(v.begin(), v.end(), b[j]) - v.begin() + 1;
	vector<ll> z(200001), zi(200001);
	z[0] = zi[0] = 1;
	for (int i = 1; i <= 200000; i++) {
		z[i] = z[i - 1] * 523541 % MOD;
		zi[i] = mod_inverse(z[i], MOD);
	}
	vector<ll> ha(N + 1), hb(M + 1);
	for (int i = 0; i < N; i++)
		ha[i + 1] = (ha[i] + A[i] * z[i]) % MOD;
	for (int j = 0; j < M; j++)
		hb[j + 1] = (hb[j] + B[j] * z[j]) % MOD;
	int cnt = 0;
	for (int i = 0; i + M <= N; i++) {
		if (!(a[i].second == b[0].second && a[i].first >= b[0].first)) continue;
		if (!(a[i + M - 1].second == b[M - 1].second && a[i + M - 1].first >= b[M - 1].first)) continue;
		if (f(i + 1, i + M - 1, ha, zi) != f(1, M - 1, hb, zi)) continue;
		cnt++;
	}
	cout << cnt << endl;
}