#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	srand(clock());

	int t;
	cin >> t;
	while (t --) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i ++)
			cin >> a[i];

		map<int,int> m;
		for (int i = 0; i < n; i ++) m[a[i]] ++;
		
		bool inf = 0;
		for (auto p: m) if (p.second >= n)
			inf = 1;

		if (inf) {
			cout << -1 << "\n"; continue;
		}

		auto solve = [&](int i, int j) {
			vector<int> divs;
			int d = abs(a[i] - a[j]);
			for (int i = 1; i * i <= d; i ++) {
				if (d % i == 0) {
					divs.emplace_back(i);
					divs.emplace_back(d / i);
				}
			}	
			map<int, int> mp;
			int ans = -1;
			for (auto d: divs) {
				mp.clear();
				for (int i = 0; i < n; i ++) {
					mp[(a[i]%d+d)%d] ++;
				}
				for (auto p: mp) if (p.second >= n)
					ans = max(ans, d);
			}
			return ans;
		};
		int ans = -1;
		for (int it = 1; it <= 100; it ++) {
			int i = rand() % n, j = rand() % n;
			ans = max(ans, solve(i, j));
		}
		cout << ans << "\n";
	}
}