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

#define double long double

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
double EPS = 1e-12;
int INF = 1e6;

d_d f(int x, int v, int l) {
	if (v == 0) return x > l ? d_d(0, INF) : d_d(INF, -INF);
	if (v > 0) return d_d(max(0.0L, (double)(l - x) / v), INF);
	if (v < 0) return d_d(0, (double)(l - x) / v);
}

void add(int x, int v, int l, vector<d_i>& a) {
	d_d p = f(x, v, l);
	a.pb(d_i(p.first + EPS, +1));
	a.pb(d_i(p.second - EPS, -1));
}

int main() {
	int N; cin >> N;
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	vector<d_i> a;
	rep(i, N) {
		int x, y, vx, vy;
		scanf("%d%d%d%d", &x, &y, &vx, &vy);
		add(x, vx, x1, a);
		add(-x, -vx, -x2, a);
		add(y, vy, y1, a);
		add(-y, -vy, -y2, a);
	}
	sort(a.begin(), a.end());
	int k = 0;
	for (d_i p: a) {
		k += p.second;
		if (k == N * 4) {
			printf("%.20f\n", (float)p.first);
			return 0;
		}
	}
	cout << "-1.000001" << endl;
}