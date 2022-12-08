#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string line;
	cin >> line;
	int xrun = 0;
	int ans = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == 'x') {
			xrun++;
		}
		else {
			if (xrun >= 3) {
				ans += xrun-2;
			}
			xrun = 0;

		}
	}
	if (xrun >= 3) {
		ans += xrun-2;
	}
	cout << ans << endl;
	cin >> n;
}