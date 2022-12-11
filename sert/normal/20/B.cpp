#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

void solve() {
	ll aa, bb, cc;
	cin >> aa >> bb >> cc;
	if (aa < 0) {
		aa = -aa;
		bb = -bb;
		cc = -cc;
	}
	ld a = aa, b = bb, c = cc;
	cout.precision(14);
	cout << fixed;

	if (aa == 0 && bb == 0) {
		if (cc == 0) cout << "-1\n";
		else cout << "0\n";
		return;
	}

	if (aa == 0) {
		cout << "1\n" << -c / b << "\n";
		return;
	}

	ll d2 = b * b - 4 * a * c;
	if (d2 < 0) {
		cout << "0\n";
		return;
	} else if (d2 == 0) {
		cout << "1\n" << -b / (2.0 * a) << "\n";
		return;
	} else {
		ld d = sqrtl(d2);
		cout << "2\n" << (-b - d) / (2.0 * a) << "\n" << (-b + d) / (2.0 * a) << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
#ifdef SERT
	int t = 6;
	for (int i = 1; i < t; i++) {
		solve();
	}
#endif
}