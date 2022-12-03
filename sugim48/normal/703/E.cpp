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
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<int, ll> i_ll;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

ll gcd(ll a, ll b) {
	for (; b; a %= b, swap(a, b));
	return a;
}

int main() {
	int N; ll X; cin >> N >> X;
	vector<ll> a(N);
	for (ll& x: a) cin >> x;
	if (X == 1) {
		int _i; ll mi = LLONG_MAX;
		for (int i = 0; i < N; i++)
			if (a[i] < mi) {
				_i = i;
				mi = a[i];
			}
		cout << 1 << endl;
		cout << _i + 1 << endl;
		return 0;
	}
	vector<ll> d;
	for (ll x = 1; x * x <= X; x++)
		if (X % x == 0) {
			d.push_back(x);
			if (x != X / x) d.push_back(X / x);
		}
	sort(d.begin(), d.end());
	int M = d.size();
	vector<int> mp1(1000001), mp2(1000001);
	for (int j = 0; j < M; j++) {
		if (d[j] <= 1000000)mp1[d[j]] = j;
		else mp2[X / d[j]] = j;
	}
	vector<vector<i_ll> > dp(N + 1, vector<i_ll>(M, i_ll(INT_MAX / 2, 0)));
	dp[0][0] = i_ll(0, 0);
	vector<vector<int> > prev(N + 1, vector<int>(M, -1));
	for (int i = 1; i <= N; i++) {
		dp[i] = dp[i - 1];
		for (int j = 0; j < M; j++) {
			if (dp[i - 1][j].first == INT_MAX / 2) continue;
			ll x = d[j], _x = x * gcd(a[i - 1], X / x);
			int _j;
			if (_x <= 1000000) _j = mp1[_x];
			else _j = mp2[X / _x];
			i_ll p = dp[i - 1][j]; p.first++; p.second += a[i - 1];
			if (p < dp[i][_j]) {
				dp[i][_j] = p;
				prev[i][_j] = j;
			}
		}
	}
	if (dp[N][M - 1].first == INT_MAX / 2) {
		cout << -1 << endl;
		return 0;
	}
	int j = M - 1;
	vector<int> ans;
	for (int i = N; i >= 1; i--)
		if (prev[i][j] != -1) {
			ans.push_back(i);
			j = prev[i][j];
		}
	cout << ans.size() << endl;
	for (int i: ans) cout << i << ' ';
	cout << endl;
}