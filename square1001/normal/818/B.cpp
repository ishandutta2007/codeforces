#include <iostream>
using namespace std;
int n, m, l[109], p[109]; bool used[109];
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> l[i], l[i]--;
	bool f = true;
	for (int i = 0; i < m - 1; i++) {
		int z = (l[i + 1] - l[i] + n - 1) % n + 1;
		if (!p[l[i]]) {
			if (used[z]) f = false;
			p[l[i]] = z; used[z] = true;
		}
		else if (p[l[i]] != z) f = false;
	}
	if (!f) cout << -1 << endl;
	else {
		for (int i = 0; i < n; i++) {
			if (i) cout << ' ';
			if (!p[i]) {
				for (int j = 1; j <= n; j++) {
					if (!used[j]) {
						used[j] = true;
						p[i] = j;
						break;
					}
				}
			}
			cout << p[i];
		}
		cout << endl;
	}
	return 0;
}