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
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
short INF = 20000;
double EPS = 1e-10;

int main() {
	int N; cin >> N;
	vector<int> a(N), d(N);
	rep(i, N) scanf("%d%d", &a[i], &d[i]);
	vector<ll> sum(N + 1);
	rep(i, N) sum[i + 1] = sum[i] + a[i];
	ll lb = INT_MIN, ub = INT_MAX;
	rep(i, N) {
		if (d[i] == 1) lb = max(lb, 1900 - sum[i]);
		if (d[i] == 2) ub = min(ub, 1899 - sum[i]);
	}
	if (ub == INT_MAX) {
		cout << "Infinity" << endl;
		return 0;
	}
	if (lb > ub) {
		cout << "Impossible" << endl;
		return 0;
	}
	cout << ub + sum[N] << endl;
}