#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define pii pair<int, int>

void solve() {
	int px, py;
	string s;
	cin >> px >> py >> s;

	int nu = 0;
	int nd = 0;
	int nr = 0;
	int nl = 0;

	for (char c : s) {
		if (c == 'U') nu++;
		if (c == 'D') nd++;
		if (c == 'R') nr++;
		if (c == 'L') nl++;
	}
	bool ok = true;
	if (px < 0 && 0-px > nl) ok = false;
	if (px > 0 && px > nr) ok = false;
	if (py < 0 && 0-py > nd) ok = false;
	if (py > 0 && py > nu) ok = false;

	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) solve();
}