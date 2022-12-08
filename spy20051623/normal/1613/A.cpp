#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long a1, a2, p1, p2;
	cin >> a1 >> p1;
	cin >> a2 >> p2;
	long long m = min(p1, p2);
	p1 -= m, p2 -= m;
	if (p1 > 7) {
		cout << '>' << endl;
		return;
	}
	if (p2 > 7) {
		cout << '<' << endl;
		return;
	}
	while (p1) {
		a1 *= 10;
		--p1;
	}
	while (p2) {
		a2 *= 10;
		--p2;
	}
	if (a1 > a2) cout << '>' << endl;
	else if (a1 < a2) cout << '<' << endl;
	else cout << '=' << endl;
}

int main() {
#ifndef ONLINE_JUDGE	
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}