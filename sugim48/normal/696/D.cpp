#define _USE_MATH_DEFINES
#include <algorithm>
#include <bitset>
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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };
typedef vector<vector<bool> > grid;

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

int main() {
	int N; ll L; cin >> N >> L;
	vector<int> a(N);
	for (int& x: a) cin >> x;
	vector<string> s(N);
	for (string& x: s) cin >> x;
	vector<string> t;
	t.push_back("");
	for (int i = 0; i < N; i++)
		for (int l = 1; l <= s[i].length(); l++)
			t.push_back(s[i].substr(0, l));
	int M = t.size();
	vector<vector<ll> > A(M, vector<ll>(M, -INF));
	for (int j = 0; j < M; j++)
		for (char c = 'a'; c <= 'z'; c++) {
			string S = t[j]; S.push_back(c);
			int L = S.length();
			ll sum = 0;
			for (int i = 0; i < N; i++) {
				int l = s[i].length();
				if (l <= L && S.substr(L - l) == s[i])
					sum += a[i];
			}
			int _j, ma = -1;
			for (int j = 0; j < M; j++) {
				int l = t[j].length();
				if (l > ma && l <= L && S.substr(L - l) == t[j]) {
					_j = j;
					ma = l;
				}
			}
			A[_j][j] = max(A[_j][j], sum);
		}
	A = matpow(A, L);
	ll ans = 0;
	for (int j = 0; j < M; j++)
		ans = max(ans, A[j][0]);
	cout << ans << endl;
}