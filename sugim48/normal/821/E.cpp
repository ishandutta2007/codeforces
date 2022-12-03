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
struct edge { int v; ll w; };

const int MOD = 1e9 + 7;
double EPS = 1e-10;
ll INF = LLONG_MAX / 10;

vector<vector<int> > matmul(vector<vector<int> >& a, vector<vector<int> >& b) {
	int n = a.size();
	vector<vector<int> > c(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				c[i][j] = (c[i][j] + (ll)a[i][k] * b[k][j]) % MOD;
	return c;
}

vector<vector<int> > matpow(vector<vector<int> >& a, ll m) {
	int n = a.size();
	vector<vector<int> > b(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		b[i][i] = 1;
	for (; m; m >>= 1) {
		if (m & 1) b = matmul(b, a);
		a = matmul(a, a);
	}
	return b;
}

vector<int> f(int N, vector<int> v, ll x) {
	vector<vector<int> > a(N, vector<int>(N));
	rep(i, N) rep(j, N) a[i][j] = (abs(i - j) <= 1);
	a = matpow(a, x);
	vector<int> w(N);
	rep(i, N) rep(j, N) w[i] = (w[i] + (ll)a[i][j] * v[j]) % MOD;
	return w;
}

int main() {
	int N; ll K; cin >> N >> K;
	vector<ll> a(N), b(N);
	vector<int> c(N);
	rep(i, N) cin >> a[i] >> b[i] >> c[i];
	b[N - 1] = K;
	vector<int> v(16);
	v[0] = 1;
	rep(k, N) {
		vector<int> _v(c[k] + 1);
		rep(i, c[k] + 1) _v[i] = v[i];
		_v = f(c[k] + 1, _v, b[k] - a[k]);
		while (_v.size() < 16) _v.pb(0);
		v = _v;
	}
	int ans = v[0];
	cout << ans << endl;
}