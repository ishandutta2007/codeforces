#include <bits/stdc++.h>

using namespace std;
const long long inf = 1e15;
const int N = 5e5 + 5;
long long a[N], s[N], v[N], dp[N];

struct node {
	int l, r;
	long long v;
} tr[N << 2];

#define T tr[n]
#define LS tr[n<<1]
#define RS tr[n<<1|1]

void build(int n, int l, int r) {
	T.l = l, T.r = r, T.v = -inf;
	if (l == r) return;
	int m = (l + r) >> 1;
	build(n << 1, l, m);
	build(n << 1 | 1, m + 1, r);
}

void upd(int n, int x, long long k) {
	if (T.l == T.r) {
		T.v = max(T.v, k);
		return;
	}
	long long m = (T.l + T.r) >> 1;
	if (x <= m) upd(n << 1, x, k);
	else upd(n << 1 | 1, x, k);
	T.v = max(LS.v, RS.v);
}

long long qry(int n, int x) {
	if (T.r <= x) return T.v;
	if (T.l > x) return -inf;
	long long res = -inf;
	res = max(res, qry(n << 1, x));
	res = max(res, qry(n << 1 | 1, x));
	return res;
}

void solve() {
	int n;
	cin >> n;
	map<long long, int> mp;
	mp[0];
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
		mp[s[i]];
	}
	int cnt = 0;
	for (auto &i: mp) i.second = ++cnt;
	for (int i = 1; i <= n; ++i) {
		v[i] = mp[s[i]];
	}
	build(1, 0, cnt);
	upd(1, mp[0], 0);
	for (int i = 1; i <= n; ++i) {
		long long res = qry(1, v[i] - 1);
		dp[i] = dp[i - 1] + (!a[i] ? 0 : a[i] / abs(a[i]));
		if (res != -inf) {
			dp[i] = max(dp[i], res + i);
		}
		upd(1, v[i], dp[i] - i);
	}
	cout << dp[n] << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}