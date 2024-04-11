#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

const int MAXN = 1e6  + 10;

int dp[MAXN];
vector<pair<int, int>> a;
int n;

void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a)
		cin >> i.first >> i.second;
	sort(all(a));
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		int pos = a[i].first - a[i].second;
		int x = lower_bound(all(a), make_pair(pos, (int)-1e9)) - a.begin();
		chkmax(dp[i + 1], dp[x] + 1);
	}
	int ans = 0;
	for (int i = 0; i < MAXN; i++)
		chkmax(ans, dp[i] + 1);
	cout << n - ans + 1 << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}