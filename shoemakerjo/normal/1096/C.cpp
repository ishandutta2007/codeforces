#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, ang;
	cin >> T;
	while (T--) {
		cin >> ang;
		bool ok = false;
		for (int i = 3; i <= 1000; i++) {
			if (ang * i % 180 == 0 && ang * i / 180 <= i-2) {
				cout << i << '\n';
				ok = true;
				break;
			}
		}
		if (!ok) cout << -1 << endl;

	}
	cout.flush();
}