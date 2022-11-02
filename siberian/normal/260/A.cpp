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
	int a, b, n;
	cin >> a >> b >> n;
	vector<int> ans(n, -1);
	int mod = a % b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			if ((mod * 10 + j) % b == 0) {
				ans[i] = j;
				mod = 0;
				break;
			}
		}
		if (ans[i] == -1) {
			cout << -1 << endl;
			return;
		}
	}
	cout << a;
	for (auto i: ans)
		cout << i;
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