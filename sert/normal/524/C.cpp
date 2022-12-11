#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<bool> u((int)1e7 + 34, false);
	for (int &x : a) {
		cin >> x;
		u[x] = true;
	}

	int q;
	cin >> q;
	while (q--) {
		int sum;
		cin >> sum;
		bool fnd = false;
		for (int tot = 1; tot <= k && !fnd; tot++) {
			for (int i = 0; i < n && !fnd; i++) {
				for (int n1 = 1; n1 <= tot && a[i] * n1 <= sum && !fnd; n1++) {
					int n2 = tot - n1;
					int need = sum - a[i] * n1;
					if (n2 == 0 && need != 0) continue;
					if (need == 0 || (need % n2 == 0 && need / n2 < (int)u.size() && u[need / n2])) {
						cout << tot << "\n";
						fnd = true;
					}
				}
			}
		}
		if (!fnd) cout << "-1\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
#ifdef SERT
	int t = 2;
	for (int i = 1; i < t; i++) {
		solve();
	}
#endif
}