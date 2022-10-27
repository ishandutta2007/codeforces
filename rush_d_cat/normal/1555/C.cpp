#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t; cin >> t;
	while (t --) {
		int m;
		cin >> m;
		vector<int> a(m), b(m), sa(m), sb(m);
		for (int i = 0; i < m; i ++) {
			cin >> a[i];
			sa[i] = (i>=1?sa[i-1]:0) + a[i];
		}
		for (int i = 0; i < m; i ++) {
			cin >> b[i];	
			sb[i] = (i>=1?sb[i-1]:0) + b[i];
		}
		int ans = 2e9;
		for (int i = 0; i < m; i ++) {
			//printf("%d %d\n", i>=1?sa[i-1]:0, sb[m - 1] - sb[i]);
			ans = min(ans, max(i>=1?sb[i-1]:0, sa[m - 1] - sa[i]));
		}
		cout << ans << "\n";
	}
}