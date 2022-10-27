#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		int n;
		cin >> n;
		vector<ll> s(n);
		for (int i = 0; i < n; i ++)
			cin >> s[i];
		sort(s.begin(), s.end());
		ll ans = -1e18;
		ll pre = 0;
		for (auto x: s) {
			ans = max(ans, x - pre);
			pre += x - pre;
		}
		cout << ans << "\n";
	}
}