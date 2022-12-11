#include <bits/stdc++.h>
using namespace std;

void solve() {
	int foo = 0, bar = 0, baz = 0, quz = 1;
	int tux;
	cin >> tux;
	while (tux--) {
		int pur;
		cin >> pur;
		foo += pur;
		bar++;
		if (max(foo * quz, bar * baz) == foo * quz) {
			baz = foo;
			quz = bar;
		}
	}
	cout << baz * 1.0 / quz << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
#ifdef SERT
	int t = 1;
	for (int i = 1; i < t; i++) {
		solve();
	}
#endif
}