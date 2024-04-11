#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
#define int ll
int d, m;

int add(int a, int b) {
	a += b;
	if (a >= m)
		a -= m;
	return a;
}

int sub(int a, int b) {
	a -= b;
	if (a < 0)
		a += m;
	return a;
}

int mul(int a, int b) {
	return (ll) a * b % m;
}

const int MAXN = 32;
int pows[MAXN];
int dp[MAXN][MAXN];

void build() {
	pows[0] = 1;
	for (int i = 1; i < MAXN; i++)
		pows[i] = mul(2, pows[i - 1]);
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			dp[i][j] = 0;
}

void solve() {
	cin >> d >> m;
	d++;
	build();
	for (int i = 0; i < MAXN; i++) {
		if ((1LL << i) > d) break;
		if ((1LL << (i + 1)) > d) {
			dp[1][i] = sub(d % m, pows[i]);
		} else {
			dp[1][i] = pows[i];
		}
	}
	for (int len = 2; len < MAXN; len++) {
		for (int bit = len - 1; bit < MAXN; bit++) {
			if ((1LL << bit) > d) break;
			int nxt = pows[bit];
			if ((1LL << (bit + 1)) > d) 
				nxt = sub(d % m, pows[bit]);
			for (int last_bit = 0; last_bit < bit; last_bit++) {
				dp[len][bit] = add(dp[len][bit], mul(nxt, dp[len - 1][last_bit]));
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			ans = add(ans, dp[i][j]);
	cout << ans << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}