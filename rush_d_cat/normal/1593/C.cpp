#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		int n, k;
		cin >> n >> k;
		vector<int> x(k);
		for (int i = 0; i < k; i ++)
			cin >> x[i];
		
		sort(x.begin(), x.end());
		int ans = 0;
		for (ll i = k - 1, sum = 0; i >= 0; i --) {
			sum += n - x[i];
			if (sum < n) {
				ans ++;
			} else break;
		}
		cout << ans << "\n";
	}
}