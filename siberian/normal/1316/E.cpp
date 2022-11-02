#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 1e5 + 10, MAXP = 7;

int n, p, k;
int a[MAXN];
int b[MAXN][MAXP];

void read() {
	cin >> n >> p >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			cin >> b[i][j];
		}
	}
}

int get(int mask) {
	int ans = 0;
	while (mask) {
		ans += mask % 2;
		mask /= 2;
	}
	return ans;
}

const ll INF = -1e18;
ll dp[MAXN][(1 << MAXP)];
ll ans;

void run() {
	vector<int> order(n);
	iota(all(order), 0);
	sort(all(order), [&] (int i, int j) {return a[i] > a[j];});
	for (int i = 0; i <= n; i++) {
		for (int mask = 0; mask < (1 << p); mask++) {
			dp[i][mask] = INF;
		}
	}
	dp[0][0] = 0;

	for (int i = 1; i <= n; i++) {
		int x = order[i - 1];
		for (int mask = 0; mask < (1 << p); mask++) {
			dp[i][mask] = dp[i - 1][mask];
			for (int bit = 0; bit < p; bit++) {
				if (!((mask >> bit) & 1)) continue;
				if (dp[i - 1][mask ^ (1 << bit)] == INF) continue;
				chkmax(dp[i][mask], dp[i - 1][mask ^ (1 << bit)] + b[x][bit]);
			}
			
			if (i - get(mask) - 1 < k) {
				if (dp[i - 1][mask] != INF) {
					chkmax(dp[i][mask], dp[i - 1][mask] + a[x]);
				}
			}
		}
	}

	/*cout << "order = " << endl;
	for (auto i : order)
		cout << i << " ";
	cout << endl;

	cout << "dp = " << endl;
	for (int i = 0; i <= n; i++) {
		for (int mask = 0; mask < (1 << p); mask++) {
			cout << dp[i][mask] << " ";
		}
		cout << endl;
	}
	*/
	
	ans = 0;
	for (int i = 0; i <= n; i++) {
		chkmax(ans, dp[i][(1 << p) - 1]);
	}
}

void write() {
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}