#include <bits/stdc++.h>
using namespace std;
int T;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	while (T --) {
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i ++) cin >> a[i];
		int mn = *min_element(a.begin(), a.end());
		int ans = 0;
		for (auto x: a) if (x > mn) ans ++;
		cout << ans << endl;
	}
}