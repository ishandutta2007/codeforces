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

ll MOD = 932432827;
ll mod = 1000000007;
double EPS = 1e-10;
double INF = FLT_MAX;

ll extgcd(ll a, ll b, ll& x, ll& y) {
	if (b == 0) {
		x = (a >= 0) ? 1 : -1;
		y = 0;
		return abs(a);
	}
	else {
		ll res = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
		return res;
	}
}

ll mod_inverse(ll a, ll m) {
	ll x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}

ll f(int l, int r, vector<ll>& ai, vector<ll>& h) {
	ll x = (h[r] - h[l]) * ai[l] % MOD;
	return (x + MOD) % MOD;
}

int main() {
	int n; cin >> n;
	string s; cin >> s;
	vector<ll> a(n + 1), ai(n + 1);
	a[0] = ai[0] = 1;
	for (int i = 1; i <= n; i++) {
		a[i] = a[i - 1] * 37 % MOD;
		ai[i] = mod_inverse(a[i], MOD);
	}
	vector<ll> h(n + 1);
	for (int i = 1; i <= n; i++)
		h[i] = (h[i - 1] + a[i - 1] * (s[i - 1] - '0' + 1)) % MOD;
	vector<string> v(n + 1);
	for (int i = 0; i <= n; i++)
		v[i] = s.substr(i);
	sort(v.begin(), v.end());
	vector<int> rank(n + 1);
	for (int i = 0; i <= n; i++)
		rank[n - v[i].length()] = i;
	vector<vector<ll> > dp(n + 1, vector<ll>(n + 1));
	dp[0][0] = 1;
	for (int l = 0; l <= n; l++)
		for (int r = l + 1; r <= n; r++) {
			dp[l][r] = (dp[l][r] + dp[l][r - 1]) % mod;
			if (s[l] == '0') dp[l][r] = 0;
			int x = r * 2 - l;
			if (x <= n && f(l, r, ai, h) != f(r, x, ai, h) && rank[l] < rank[r])
				dp[r][x] = (dp[r][x] + dp[l][r]) % mod;
			else if (x + 1 <= n)
				dp[r][x + 1] = (dp[r][x + 1] + dp[l][r]) % mod;
		}
	ll sum = 0;
	for (int l = 0; l <= n; l++)
		sum = (sum + dp[l][n]) % mod;
	cout << sum << endl;
}