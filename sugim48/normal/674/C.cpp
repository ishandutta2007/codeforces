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

ll a[200010], A[200010];
double b[200010], B[200010], C[200010];

double f(int l, int r) {
	return C[r] - C[l] - A[l] * (B[r] - B[l]);
}

int main() {
	int N, K; cin >> N >> K;
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < N; i++)
		b[i] = 1.0 / a[i];
	for (int i = 0; i < N; i++) {
		A[i + 1] = A[i] + a[i];
		B[i + 1] = B[i] + b[i];
	}
	for (int i = 0; i < N; i++)
		C[i + 1] = C[i] + A[i + 1] * b[i];
	vector<double> d(N + 1);
	for (int i = 0; i <= N; i++)
		d[i] = f(i, N);
	while (--K) {
		vector<double> _d(N + 1);
		int M = 0;
		vector<int> v;
		for (int i = N; i >= 0; i--) {
			for (; M >= 2 && (d[v[M - 2]] + C[v[M - 2]] - d[v[M - 1]] - C[v[M - 1]]) / (B[v[M - 2]] - B[v[M - 1]]) <= (d[v[M - 1]] - d[i] + C[v[M - 1]] - C[i]) / (B[v[M - 1]] - B[i]); M--, v.pop_back());
			M++; v.push_back(i);
			int lb = 0, ub = M - 1;
			while (ub - lb > 1) {
				int mid = (lb + ub) / 2;
				int i1 = v[mid], i2 = v[mid + 1];
				if (d[i1] + f(i, i1) > d[i2] + f(i, i2)) lb = mid;
				else ub = mid;
			}
			_d[i] = d[v[lb]] + f(i, v[lb]);
			if (lb + 1 < M) _d[i] = min(_d[i], d[v[lb + 1]] + f(i, v[lb + 1]));
		}
		d = _d;
	}
	printf("%.15f\n", d[0]);
}