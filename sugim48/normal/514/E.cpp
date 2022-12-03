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
struct edge { int u, v, w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;
int INF = INT_MAX / 2;

vector< vector<ll> > matmul(vector< vector<ll> >& A, vector< vector<ll> >& B) {
	int n = A.size();
	vector< vector<ll> > C(n, vector<ll>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
	return C;
}

vector< vector<ll> > matpow(vector< vector<ll> > A, ll x) {
	int n = A.size();
	vector< vector<ll> > B(n, vector<ll>(n));
	for (int i = 0; i < n; i++) B[i][i] = 1;
	while (x > 0) {
		if (x % 2) B = matmul(B, A);
		x /= 2;
		A = matmul(A, A);
	}
	return B;
}

int main() {
	int n, x; cin >> n >> x;
	vector<int> a(100);
	while (n--) {
		int d; scanf("%d", &d);
		a[d - 1]++;
	}
	vector<vector<ll> > A(101, vector<ll>(101));
	for (int i = 0; i < 100; i++)
		A[0][i] = a[i];
	A[0][100] = 1;
	for (int i = 0; i < 99; i++)
		A[i + 1][i] = 1;
	A[100][100] = 1;
	vector<vector<ll> > B = matpow(A, x + 1);
	cout << B[0][100] << endl;
}