#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		int n; 
		string ch, s;
		cin >> n >> ch >> s;
		set<int> st;
		for (int i = 0; i < n; i ++) {
			if (s[i] != ch[0]) {
				st.insert(i + 1);
			}
		}
		if (st.size() == 0) {
			cout << 0 << "\n";
		} else {
			bool ok = 0;
			for (int i = n; i >= 1; i --) {
				if (st.count(i) == 0) {
					if (2 * i > n) {
						ok = 1;
						cout << 1 << "\n" << i << "\n";
					}
					break;
				}
			}
			if (not ok) {
				cout << 2 << "\n";
				cout << n << " ";
				for (int x = 2; x < n; x ++) if (n % x) {
					cout << x << "\n"; break;
				}
			}
		}

	}
}