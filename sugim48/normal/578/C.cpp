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

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

double f(int n, vector<int>& a, double x) {
	vector<double> sum(n + 1);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i - 1] - x;
	double mini = DBL_MAX, maxi = -DBL_MAX;
	for (int i = 0; i <= n; i++) {
		mini = min(mini, sum[i]);
		maxi = max(maxi, sum[i]);
	}
	return maxi - mini;
}

int main() {
	int n; cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	double a = -11000, b = 11000;
	for (int t = 0; t < 100; t++) {
		double c1 = (a * 2 + b) / 3, c2 = (a + b * 2) / 3;
		double f1 = f(n, A, c1), f2 = f(n, A, c2);
		if (f1 < f2) b = c2;
		else a = c1;
	}
	printf("%.15f\n", f(n, A, a));
}