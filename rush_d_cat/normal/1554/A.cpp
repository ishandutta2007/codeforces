#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int t; cin >> t;
	while (t --) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i ++) cin >> a[i];
		LL ans = 0;
		for (int i = 0; i + 1 < n; i ++) ans = max(ans, 1LL * a[i] * a[i+1]);
		cout << ans << endl;
	}
}