#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n0, n1, n2;
	cin >> n0 >> n1 >> n2;
	if (n0) for (int i = 0; i < n0 + 1; i++) cout << "0";
	if (n2) for (int i = 0; i < n2 + 1; i++) cout << "1";
	int lst = (n2 ? 1 : 0);
	int num = (n0 * n2 ? n1 - 1 : n1);
	if (n0 + n2 == 0) num = n1 + 1;
	for (int i = 0; i < num; i++) {
		lst = 1 - lst;
		cout << lst;
	}
	cout << "\n";
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