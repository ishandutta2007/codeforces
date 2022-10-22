#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef double ld;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 2e5 + 10;
const ll MAXK = 50 + 5;

int n, k;
double ps[MAXN], ps_i[MAXN], f[MAXN], dp[MAXK][MAXN];

inline ld calc(int l, int r) {
	return f[r] - f[l - 1] - (ps_i[r] - ps_i[l - 1]) * ps[l - 1];
}

void solve(int k, int l = 1, int r = n, int opt_l = 0, int opt_r = n) {
	if (r < l) return;

	int mid = (l + r) >> 1, opt = opt_l;
	dp[k][mid] = f[mid];

	for (int i = opt_l; i <= min(mid, opt_r); i++) {
		ld ans = dp[k - 1][i - 1] + calc(i, mid);
		if (ans < dp[k][mid]) {
			dp[k][mid] = ans;
			opt = i;
		}
	}

	solve(k, l, mid - 1, opt_l, opt);
	solve(k, mid + 1, r, opt, opt_r);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		ps[i] = ps[i - 1] + x;
		ps_i[i] = ps_i[i - 1] + 1 / ld(x);
		dp[1][i] = f[i] = f[i - 1] + ps[i] / ld(x);
	}

	for (int i = 2; i <= k; i++)
		solve(i);

	cout << setprecision(10) << fixed << dp[k][n] << endl;
	return 0;
}