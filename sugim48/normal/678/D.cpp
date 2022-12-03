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

int main() {
	ll A, B, x, n; cin >> A >> B >> n >> x;
	vector<vector<int> > a(3, vector<int>(3));
	a[0][0] = A;
	a[1][1] = A; a[1][2] = B;
	a[2][2] = 1;
	a = matpow(a, n);
	ll _A = (a[0][0] + a[0][2]) % MOD, _B = (a[1][0] + a[1][2]) % MOD;
	cout << (x * _A + _B) % MOD << endl;
}