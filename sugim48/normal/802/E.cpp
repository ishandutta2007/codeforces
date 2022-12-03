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
double EPS = 1e-10;

const int N = 250;

double F[10001];

double uniform(int N, vector<int> a, int p) {
	double sum = 0;
	rep(i, N) {
		if (0 <= a[i] && a[i] <= p * 2) sum += log(1.0 / (p * 2 + 1));
		else return -DBL_MAX;
	}
	return sum;
}

double poisson(int N, vector<int> a, int p) {
	double sum = 0;
	rep(i, N) {
		sum += log(p) * a[i];
		sum += -p;
		sum -= F[a[i]];
	}
	return sum;
}

int main() {
	for (int x = 1; x <= 10000; x++)
		F[x] = F[x - 1] + log(x);
	int T; cin >> T;
	while (T--) {
		vector<int> a(N);
		rep(i, N) scanf("%d", &a[i]);
		double ma = -DBL_MAX;
		int p0;
		for (int p = 10; p <= 1000; p++) {
			double q = max(uniform(N, a, p), poisson(N, a, p));
			if (q > ma) ma = q, p0 = p;
		}
		cout << p0 << endl;
	}
}