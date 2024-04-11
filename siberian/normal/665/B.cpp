#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
#define int ll

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> have(k);
	for (auto &i : have)
		cin >> i;
	int ans = 0;
	for (int i = 0; i < n * m; i++) {
		int x;
		cin >> x;
		for (int j = 0; j < have.size(); j++) {
			ans++;
			if (have[j] == x) {
				have.erase(have.begin() + j);
				reverse(all(have));
				have.push_back(x);
				reverse(all(have));
				break;
			}
		}
	}
	cout << ans;
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