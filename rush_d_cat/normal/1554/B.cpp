#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int t; cin >> t;
	while (t --) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i ++) cin >> a[i];
		LL ans = 1LL * n * (n-1) - 1LL * k * (a[n-1] | a[n-2]);
		for (int i = n - 1; i >= 0; i --) {
			for (int j = n - 1; j > i; j --) {
				if (1LL* (i+1) * (j+1) <= ans) break;
				ans = max(ans, 1LL*(i+1)*(j+1) - 1LL * k * (a[i] | a[j]));
			}
		}
		cout << ans << endl;
	}
}