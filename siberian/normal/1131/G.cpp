#include <bits/stdc++.h>

using namespace std;
//#define int long long
#define pb push_back
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 1e7 + 10;

int m;
pair<int, long long> a[MAXN];
const long long INF = 1e18;

long long ans;
long long dp[MAXN];
pair <int, long long> help[MAXN];
int x2[MAXN];
int x1[MAXN];
int pos = 0;

void read() {
	int n;
	cin >> n >> m;
	vector<vector<pair <int, long long> > > fa(n);
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		fa[i].resize(k);
		for (auto &j : fa[i])
			cin >> j.first;
		for (auto &j : fa[i])
			cin >> j.second;
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		long long id, mul;
		cin >> id >> mul;
		id--;
		for (auto j : fa[id])
			a[pos++] = {j.first, j.second * mul};
	}
	fa.clear();
}

void gen_l() {
	pos = 0;
	for (int i = 0; i < m; i++) {
		help[pos++] = {i, max(i - a[i].first + 1LL, 0LL)};
		while (pos >= 2) {
			auto h1 = help[pos - 1];
			pos--;
			auto h2 = help[pos - 1];
			pos--;
			if (h1.second <= h2.first) {
				chkmin(h1.second, h2.second);
				help[pos++] = h1;
			}
			else {
				help[pos++] = h2;
				help[pos++] = h1;
				break;
			}
		}
		x1[i] = help[pos - 1].second;
	}
}

void get_r() {
	pos = 0;
	for (int i = m - 1; i >= 0; i--) {
		help[pos++] = {i, min(i + a[i].first - 1LL, m - 1LL)};
		while (pos >= 2) {
			auto h1 = help[pos - 1];
			pos--;
			auto h2 = help[pos - 1];
			pos--;
			if (h1.second >= h2.first) {
				chkmax(h1.second, h2.second);
				help[pos++] = h1;
			}
			else {
				help[pos++] = h2;
				help[pos++] = h1;
				break;
			}
		}
		x2[i] = help[pos - 1].second;
	}
}

void run() {
	gen_l();
	get_r();

	pos = 0;

	help[pos++] = {0, 0LL};

	for (int i = 0; i < MAXN; i++)
		dp[i] = INF;
	dp[0] = 0;

	for (int i = 0; i < m; i++) {
		while (pos >= 2) {
			auto h1 = help[pos - 1];
			pos--;
			auto h2 = help[pos - 1];
			pos--;
			if (h2.first >= x1[i]) {
				help[pos++] = h2;
			}
			else {
				help[pos++] = h2;
				help[pos++] = h1;
				break;
			}
		}

		chkmin(dp[i + 1], a[i].second + (x1[i] == 0 ? 0LL : help[pos - 1].second));
		chkmin(dp[x2[i] + 1], a[i].second + dp[i]);
		
		while (pos > 0 && help[pos - 1].second >= dp[i + 1])
			pos--;
		help[pos++] = {i + 1, dp[i + 1]};
	}

	ans = dp[m];
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