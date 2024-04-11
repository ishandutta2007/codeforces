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

ll INF = LLONG_MAX / 10;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int N; cin >> N;
	vector<double> p(N);
	for (int i = 0; i < N; i++) {
		cin >> p[i];
		p[i] /= 100;
	}
	vector<double> a(N, 1);
	double e = 0;
	for (int t = 0; t < 1000000; t++) {
		double x = 1;
		for (int i = 0; i < N; i++)
			x *= 1 - a[i];
		e += 1 - x;
		int k; double mi = DBL_MAX;
		for (int i = 0; i < N; i++) {
			double x = (1 - a[i]) / (1 - a[i] * (1 - p[i]));
			if (x < mi) {
				k = i;
				mi = x;
			}
		}
		a[k] *= 1 - p[k];
	}
	printf("%.15f\n", e);
}