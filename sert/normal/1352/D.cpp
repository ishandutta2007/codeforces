#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	int c1 = 1;
	int c2 = n - 1;
	int sum = a[0];
	int s1 = sum, s2 = 0;
	if (n == 1) {
		cout << "1 " << a[0] << " 0\n";
		return;
	}
	for (int it = 0; true; it++) {
		int s = 0;
		if (it % 2 == 0) {
			while (c2 >= c1 && s <= sum) {
				s += a[c2--];
			}
			s2 += s;
		} else {
			while (c1 <= c2 && s <= sum) {
				s += a[c1++];
			}
			s1 += s;
		}
		if (s <= sum || c1 > c2) {
			cout << it + 2 << " " << s1 << " " << s2 << "\n";
			return;
		}
		sum = s;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}