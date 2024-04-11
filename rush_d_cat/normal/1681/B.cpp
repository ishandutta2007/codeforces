#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);

	int t;
	cin >> t;
	while (t --) {
		int n, m;
		
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i ++)
			cin >> a[i];
		int idx = 0;
		cin >> m;
		vector<int> b(m);
		for (int i = 0; i < m; i ++) {
			cin >> b[i];
			(idx += b[i]) %= n;
		}
		cout << a[idx] << "\n";
	}
}