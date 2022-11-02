#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int n;
	cin >> n;
	vector<int> have;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			have.push_back(i);
			have.push_back(n / i);
		}
	}
	sort(all(have));
	have.resize(unique(all(have)) - have.begin());
	for (int i = 0; i < have.size(); i++) {
		for (int j = i + 1; j < have.size(); j++) {
			if (n / have[i] % have[j]) continue;
			if (n / have[i] / have[j] > have[j]) {
				cout << "YES\n";
				cout << have[i] << " " << have[j] << " " << n / have[i] / have[j] << "\n";
				return;
			}
		}
	}
	cout << "NO\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}