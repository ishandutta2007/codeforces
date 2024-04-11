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
		cin >> m;
		vector<int> b(m);
		for (int i = 0; i < m; i ++) 
			cin >> b[i];

		int m1 = *max_element(a.begin(), a.end());
		int m2 = *max_element(b.begin(), b.end());
		if (m1 >= m2) cout << "Alice" << "\n"; else cout << "Bob" << "\n";
		if (m1 <= m2) cout << "Bob" << "\n"; else cout << "Alice" << "\n";
	}
}