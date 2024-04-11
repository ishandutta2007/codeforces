#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int n;
	cin >> n;
	map <int, int> a;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[x]++;
	}
	multiset<int> help;
	for (auto i : a) {
		help.insert(-i.second);
	} 	
	/*cout << "help = ";
	for (auto i : help)
		cout << i << " ";
	cout << endl;*/
	int ans = 0;
	int now = 1e9;
	while (!help.empty() && now > 0) {
		auto q = *help.begin();
		help.erase(help.begin());
		if (-q >= now) {
			ans += now - 1;
			now--;
		}
		else if (-q < now) {
			now = -q;
			ans += -q;
		}
	}
	cout << ans << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}