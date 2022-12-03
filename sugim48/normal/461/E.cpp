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

ll INF = LLONG_MAX / 3;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

vector<vector<ll> > matmul(vector<vector<ll> >& a, vector<vector<ll> >& b) {
	int n = a.size();
	vector<vector<ll> > c(n, vector<ll>(n, -INF));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				c[i][j] = max(c[i][j], a[i][k] + b[k][j]);
	return c;
}

vector<vector<ll> > matpow(vector<vector<ll> >& a, ll m) {
	int n = a.size();
	vector<vector<ll> > b(n, vector<ll>(n, -INF));
	for (int i = 0; i < n; i++)
		b[i][i] = 0;
	for (; m; m >>= 1) {
		if (m & 1) b = matmul(b, a);
		a = matmul(a, a);
	}
	return b;
}

vector<string> w[10][4][4];

int main() {
	ll M; cin >> M;
	string s; cin >> s;
	int N = s.size();
	for (int d = 0; d < 10; d++)
		for (int l = 0; l + d + 2 <= N; l++) {
			string t = s.substr(l, d + 2);
			w[d][t.front() - 'A'][t.back() - 'A'].push_back(t);
		}
	vector<vector<int> > b(4, vector<int>(4));
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			for (int& d = b[i][j]; ; d++) {
				vector<string>& v = w[d][i][j];
				sort(v.begin(), v.end());
				v.erase(unique(v.begin(), v.end()), v.end());
				if (v.size() < (1<<(d * 2))) break;
			}
	vector<vector<ll> > a(40, vector<ll>(40, -INF));
	for (int i = 0; i < 36; i++) a[i][i + 4] = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			for (int d = b[i][j]; d < 10; d++)
				a[36 + j][(9 - d) * 4 + i] = 1;
	a = matpow(a, M - 1);
	ll ma = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			ma = max(ma, a[36 + i][36 + j]);
	cout << ma + 1 << endl;
}