#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define pii pair<int, int>

void solve() {
	int n;
	cin >> n;
	string b;
	cin >> b;
	// cin >> n;
	int prev = -1;
	for (int i = 0; i < n; i++) {
		int cur = b[i] - '0';
		if ((1+cur) != prev) {
			cout << 1;
			prev = 1+cur;
			continue;
		}
		cout << 0;
		prev = cur;
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) solve();
	cout.flush();
}