//In the name of God

#include <bits/stdc++.h>

using namespace std;

//#define double long double
typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }


const int N = 1e5 + 5, M = 105;

int read() { int x; cin >> x; return x; }

int cnt[N], a[N];
double dp[N][M], c[N * 5][6];

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read();
	double cur = 0;
	for (int i = 0; i < n; ++i) {
		cnt[i] = read();
		a[i] = cnt[i];
		dp[i][a[i]] = 1;
		cur += dp[i][0];
	}
	for (int i = 0; i < N * 5; ++i) {
		for (int j = 0; j < min(i + 1, 6); ++j) {
			if (j == i || !j) {
				c[i][j] = 1;
			} else {
				c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			}
		}
	}
	int q = read();
	while (q--) {
		int u = read() - 1, v = read() - 1, m = read();
		cur -= dp[u][0];
		for (int i = 0; i < min(a[u] + 1, M); ++i) {
			double ans = 0;
			for (int j = i; j < min(i + m + 1, min(a[u] + 1, M)); ++j) {
				int bad = cnt[u] - j, good = j, pgood = j - i, pbad = m - pgood;
				double prob = (c[bad][pbad] * c[good][pgood]) / c[bad + good][m];
				if (prob != prob) prob = 0;
				ans += prob * dp[u][j];
			}
			dp[u][i] = ans;
		}
		cur += dp[u][0];
		cnt[v] += m;
		cnt[u] -= m;
		cout << setprecision(9) << fixed << cur << '\n';
	}
}