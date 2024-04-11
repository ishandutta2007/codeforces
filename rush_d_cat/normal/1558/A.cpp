#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		int a, b;
		cin >> a >> b;
		int ca = (a + b + 1) / 2;
		int cb = (a + b) / 2;
		vector<int> ans;

		auto solve = [&](){
			for (int xb = 0; xb <= ca; xb ++) {
				int xa = ca - xb;
				int ya = a - xa;
				int yb = cb - ya;
				
				if (xa >= 0 && xb >= 0 && ya >= 0 && yb >= 0) {
					ans.emplace_back(xb + ya);
				}
			}
		};
		solve();
		swap(ca, cb);
		solve();
		sort(ans.begin(), ans.end());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());
		cout << ans.size() << endl;
		for (auto x: ans) cout << x << " ";
		cout << "\n";
	}	
}