//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

const int N = 2016, mod = 1e9 + 7;

int read() { int x; cin >> x; return x; }

int dp[N][N][2], n, m, dig, pw[N], flag = 1;
string c;

int go(int pos, int eq, int rem) {
	if (pos == n && rem == 0 && eq == 1)
		return flag;
	if (pos == n && rem == 0)
		return 1;
	if (pos == n)
		return 0;
	if (dp[pos][rem][eq] != -1)
		return dp[pos][rem][eq];
	int res = 0;
	int till = (eq? c[pos] - '0': 9);
	for (int i = 0; i <= till; ++i) {
		if (pos == 0 && i == 0)
			continue;
		if (pos % 2 == 1 && i != dig)
			continue;
		if (pos % 2 == 0 && i == dig)
			continue;
		int neq = eq & (i == till), nrem = (rem - (pw[n - pos - 1] * i) % m + m) % m;
		res += go(pos + 1, neq,  nrem);
		if (res >= mod)
			res -= mod;
	}
	return dp[pos][rem][eq] = res;
}

int get(string s) {
	memset(dp, -1, sizeof dp);
	c = s;
	int res = go(0, 1, 0);
	flag = 0;
	return res;
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> m >> dig;
	pw[0] = 1;
	for (int i = 1; i < N; ++i)
		pw[i] = pw[i - 1] * 1LL * 10 % m;
	string l, r;
	cin >> l >> r;
	n = (int) l.size();
	cout << (get(r) - get(l) + mod) % mod;
	
}