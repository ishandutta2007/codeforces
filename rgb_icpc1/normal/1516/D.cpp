#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define bit(x) (1 << (x))
typedef long long LL;
const int MX = 100005;
const int MK = 17;

inline int blen(int x) {
	return 32 - __builtin_clz(x);
}

struct RMQ {
	int v[MK][MX];
	int n;
	void build(int *a, int an) {
		int i, k, m;
		n = an;
		for (i = 0; i < n; i++) v[0][i] = a[i];
		for (k = 0; (m = n - bit(k + 1)) >= 0; k++) {
			for (i = 0; i <= m; i++) v[k + 1][i] = min(v[k][i],
			v[k][i + bit(k)]);
		}
	}
	int get(int st, int en) {
		int k = blen(en - st) - 1;
		return min(v[k][st], v[k][en - bit(k)]);
	}
} rmq;

int a[MX];
int b[MX];
int c[MX];
int p[MX];
int dp[MX][MK];

int main() {

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	for (int i = 2; i < 100005; i++) if (!b[i]) {
		for (int j = i; j < 100005; j += i) b[j] = i;
	}
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 2; i < 100005; i++) p[i] = n;
	for (int i = n - 1; i >= 0; i--) {
		int _a = a[i];
		int _c = n - 1;
		while (_a != 1) {
			int _b = b[_a];
			_c = min(_c, p[_b] - 1);
			p[_b] = i;
			while (_a % _b == 0) _a /= _b;
		}
		c[i] = _c;
//		cout << i << ' ' << c[i] << endl;
	}
//	cout << endl;
	rmq.build(c, n);
	for (int i = 0; i < n; i++) {
		dp[i][0] = rmq.get(i, c[i] + 1);
//		cout << i << ' ' << dp[i][0] << endl;
	}
	dp[n][0] = n;
	for (int j = 1; j < MK; j++) {
		for (int i = 0; i < n; i++) {
			if (dp[i][j - 1] == n) dp[i][j] = n;
			else dp[i][j] = dp[dp[i][j - 1] + 1][j - 1];
		}
		dp[n][j] = n;
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--; r--;
		int rlt = 0;
		for (int j = MK - 1; j >= 0; j--) {
//			cout << l << ' ' << dp[l][j] << ' ' << r << endl;
			if (r < dp[l][j]) continue;
			rlt += bit(j);
			if (r == dp[l][j]) {
				l = dp[l][j] + 1;
				break;
			}
			l = dp[l][j] + 1;
		}
		if (l != r + 1) {
			assert(l <= r);
//			cout << dp[l][0] << ' ' << r << endl;
			assert(dp[l][0] > r);
			rlt += 1;
		}
		cout << rlt << endl;
	}
	
	return 0;

}