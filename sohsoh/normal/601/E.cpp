#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 2e5 + 10;
const ll MAXK = 1e3 + 10;
const ll MAXH = 18;
const ll P = 1e7 + 19;
const ll MOD = 1e9 + 7;

int lst[MAXN], n, k, q, dp[MAXH][MAXK], pw[MAXK];
pll E[MAXN];
bool Q[MAXN];
vector<pll> vec[MAXN];

inline void add(int ql, int qr, pll e, int l = 1, int r = q, int v = 1) {
	if (ql > r || qr < l) return;
	if (ql <= l && qr >= r) {
		vec[v].push_back(e);
		return;
	}

	int mid = (l + r) >> 1;
	add(ql, qr, e, l, mid, v << 1);
	add(ql, qr, e, mid + 1, r, v << 1 | 1);
}

void solve(int l = 1, int r = q, int v = 1, int h = 1) {
	for (int i = 0; i <= k; i++)
		dp[h][i] = dp[h - 1][i];
	for (pll e : vec[v])
		for (int i = k; i >= e.Y; i--)
			dp[h][i] = max(dp[h][i], dp[h][i - e.Y] + e.X);

	if (l == r && Q[l]) {
		ll ans = 0;
		for (int i = 1; i <= k; i++)
			ans = (ans + 1ll * dp[h][i] * pw[i - 1]) % MOD;

		cout << ans << endl;
	}

	if (l < r) {
		int mid = (l + r) >> 1;
		solve(l, mid, v << 1, h + 1);
		solve(mid + 1, r, v << 1 | 1, h + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	pw[0] = 1;
	for (int i = 1; i < MAXK; i++)
		pw[i] = pw[i - 1] * P % MOD;

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		lst[i] = 1;
		cin >> E[i].X >> E[i].Y;
	}

	cin >> q;
	for (int i = 1; i <= q; i++) {
		int c;
		cin >> c;
		if (c == 1) {
			lst[++n] = i;
			cin >> E[n].X >> E[n].Y;
		} else if (c == 2) {
			int x;
			cin >> x;
			add(lst[x], i, E[x]);
			lst[x] = 0;
		} else Q[i] = true;
	}

	for (int i = 1; i <= n; i++)
		if (lst[i])
			add(lst[i], q, E[i]);

	solve(1, q);
	return 0;
}