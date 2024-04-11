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

double INF = DBL_MAX / 10;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

double f(ll dx, ll dy) {
	return sqrt(dx * dx + dy * dy);
}

int main() {
	ll ax, ay, bx, by, tx, ty;
	cin >> ax >> ay >> bx >> by >> tx >> ty;
	ax -= tx; ay -= ty;
	bx -= tx; by -= ty;
	int N; cin >> N;
	vector<ll> x(N), y(N);
	for (int i = 0; i < N; i++) {
		scanf("%lld%lld", &x[i], &y[i]);
		x[i] -= tx; y[i] -= ty;
	}
	vector<double> a(N), b(N);
	for (int i = 0; i < N; i++) {
		a[i] = f(ax - x[i], ay - y[i]) - f(x[i], y[i]);
		b[i] = f(bx - x[i], by - y[i]) - f(x[i], y[i]);
	}
	vector<double> l(N + 1, INF), r(N + 1, INF);
	for (int i = 0; i < N; i++)
		l[i + 1] = min(l[i], b[i]);
	for (int i = N - 1; i >= 0; i--)
		r[i] = min(r[i + 1], b[i]);
	double mi = r[0];
	for (int i = 0; i < N; i++)
		mi = min(mi, a[i] + min(0.0, min(l[i], r[i + 1])));
	double sum = 0;
	for (int i = 0; i < N; i++)
		sum += f(x[i], y[i]) * 2;
	printf("%.15f\n", sum + mi);
}