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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

struct segment_tree {
	int n; vector<ll> v;
	segment_tree(int _n = 0) {
		for (n = 1; n < _n; n *= 2);
		v = vector<ll>(n * 2 - 1);
	}
	void set(int i, ll x) {
		int k = i + n - 1;
		v[k] += x;
		while (k > 0) {
			k = (k - 1) / 2;
			v[k] = v[k * 2 + 1] + v[k * 2 + 2];
		}
	}
	ll _get(int i, int j, int k, int l, int r) {
		if (r <= i || j <= l) return 0;
		if (i <= l && r <= j) return v[k];
		ll vl = _get(i, j, k * 2 + 1, l, (l + r) / 2);
		ll vr = _get(i, j, k * 2 + 2, (l + r) / 2, r);
		return vl + vr;
	}
	ll get(int i, int j) { return _get(i, j, 0, 0, n); }
};

vector<int> len;
segment_tree ang;

struct arm {
	int n; vector<double> x, y;
	arm(int _n) {
		for (n = 1; n < _n; n *= 2);
		len = vector<int>(n);
		ang = segment_tree(_n);
		x = y = vector<double>(n * 2 - 1);
	}
	void update(int i) {
		int k = i + n - 1;
		x[k] = len[i]; y[k] = 0;
		while (k > 0) {
			k = (k - 1) / 2;
			double a = ang.v[k * 2 + 1] * M_PI/180;
			x[k] = x[k * 2 + 1] + x[k * 2 + 2] * cos(a) - y[k * 2 + 2] * sin(a);
			y[k] = y[k * 2 + 1] + x[k * 2 + 2] * sin(a) + y[k * 2 + 2] * cos(a);
		}
	}
};

int main() {
	int N, M; cin >> N >> M;
	arm a(N);
	for (int i = 0; i < N; i++)
		len[i] = 1;
	for (int i = 0; i < N; i++)
		a.update(i);
	int ang0 = 0;
	while (M--) {
		int q, i, z;
		scanf("%d%d%d", &q, &i, &z);
		i--;
		if (q == 1) len[i] += z;
		if (q == 2) {
			if (i) ang.set(i - 1, z);
			else ang0 += z;
		}
		if (i - 1 >= 0) a.update(i - 1);
		a.update(i);
		if (i + 1 < N) a.update(i + 1);
		double x = a.x[0] * cos(ang0 * M_PI/180) - a.y[0] * sin(ang0 * M_PI/180);
		double y = a.x[0] * sin(ang0 * M_PI/180) + a.y[0] * cos(ang0 * M_PI/180);
		printf("%.15f %.15f\n", x, -y);
	}
}