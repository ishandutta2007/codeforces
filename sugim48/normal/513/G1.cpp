#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
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
struct edge { int u; ll V; int v; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

vector< vector<double> > matmul(vector< vector<double> >& A, vector< vector<double> >& B) {
	int n = A.size();
	vector< vector<double> > C(n, vector<double>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]);
	return C;
}

vector< vector<double> > matpow(vector< vector<double> > A, ll x) {
	int n = A.size();
	vector< vector<double> > B(n, vector<double>(n));
	for (int i = 0; i < n; i++) B[i][i] = 1;
	while (x > 0) {
		if (x % 2) B = matmul(B, A);
		x /= 2;
		A = matmul(A, A);
	}
	return B;
}

int main() {
	int n, k; cin >> n >> k;
	vector< vector<double> > a(n * n, vector<double>(n * n));
	int m = n * (n + 1) / 2;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			int x = i * n + j;
			for (int l = 0; l <= n; l++)
				for (int r = l + 1; r <= n; r++) {
					int _i = i, _j = j;
					if (i >= l && i < r) _i = l + r - i - 1;
					if (j >= l && j < r) _j = l + r - j - 1;
					int y = _i * n + _j;
					a[x][y] += 1.0 / m;
				}
		}
	a = matpow(a, k);
	vector<int> p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i];
	double e = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			double sum = 0;
			for (int _i = 0; _i < n; _i++)
				for (int _j = 0; _j < n; _j++)
					if (_i > _j)
						sum += a[i * n + j][_i * n + _j];
			if (p[i] < p[j]) e += sum;
			else e += 1 - sum;
		}
	printf("%.15f\n", e);
}