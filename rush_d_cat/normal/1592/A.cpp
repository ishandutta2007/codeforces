#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);

	int t;
	cin >> t;
	while (t --) {
		int n, h;
		cin >> n >> h;
		vector<int> a(n);
		for (int i = 0; i < n; i ++)
			cin >> a[i];

		sort(a.begin(), a.end());
		int sum = a[a.size() - 1] + a[a.size() - 2];
		int ans = 2 * (h / sum);
		h -= (h / sum) * sum;
		if (h > 0) ans ++;
		if (h > a.back()) ans ++;
		cout << ans << "\n";
	}
}