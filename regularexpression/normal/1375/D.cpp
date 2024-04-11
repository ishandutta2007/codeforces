#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		
		vector<int> ans;
		while (!is_sorted(a.begin(), a.end())) {
			vector<int> u(n + 1);
			for (int i = 0; i < n; ++i)
				++u[a[i]];
			int x = 0;
			while (u[x] > 0) ++x;
			if (x == n) {
				for (int i = 0; i < n; ++i) 
					if (a[i] != i) {
						ans.push_back(i + 1);
						a[i] = n;
						break;
					}
			} else {
				ans.push_back(x + 1);
				a[x] = x;
			}
		}
		cout << ans.size() << '\n';
		for (int x : ans)
			cout << x << " ";
		cout << '\n';
	}
	return 0;
}