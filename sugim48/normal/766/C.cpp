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
#include <unordered_set>
#include <complex>
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
typedef complex<double> C;

ll MOD = 1000000007;
ll _MOD = 1000000009;
int INF = INT_MAX / 2;
double EPS = 1e-10;

bool f(int l, int r, vector<int>& a, vector<vector<int> >& sum) {
	rep(k, 26) if (sum[r][k] - sum[l][k] && r - l > a[k]) return false;
	return true;
}

int main() {
	int N; cin >> N;
	string s; cin >> s;
	vector<int> a(26);
	rep(k, 26) cin >> a[k];
	vector<vector<int> > sum(N + 1, vector<int>(26));
	for (int i = 0; i < N; i++) {
		rep(k, 26) sum[i + 1][k] = sum[i][k];
		sum[i + 1][s[i] - 'a']++;
	}
	vector<int> dp(N + 1);
	dp[0] = 1;
	for (int l = 0; l <= N; l++)
		for (int r = l + 1; r <= N; r++)
			if (f(l, r, a, sum))
				dp[r] = (dp[r] + dp[l]) % MOD;
	int ma = 0;
	for (int l = 0; l <= N; l++)
		for (int r = l + 1; r <= N; r++)
			if (f(l, r, a, sum))
				ma = max(ma, r - l);
	vector<int> _dp(N + 1, INF);
	_dp[0] = 0;
	for (int l = 0; l <= N; l++)
		for (int r = l + 1; r <= N; r++)
			if (f(l, r, a, sum))
				_dp[r] = min(_dp[r], _dp[l] + 1);
	cout << dp[N] << endl;
	cout << ma << endl;
	cout << _dp[N] << endl;
}