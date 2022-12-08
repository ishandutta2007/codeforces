#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	bool in[4];
	in[1] = in[2] = true;
	in[3] = false;
	bool ok = true;
	int n;
	cin >> n;
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		if (!in[cur]) {
			ok = false;

		}
		for (int j = 1; j <= 3; j++) {
			if (j == cur) continue;
			if (in[j]) in[j] = false;
			else in[j] = true;
		}
	}
	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;
	cin >> n;
}