#include <bits/stdc++.h>
using namespace std;

using ld = long double;

int main() {
	cout << fixed << setprecision(9);
	ios :: sync_with_stdio(false);
	int t; cin >> t;
	for(int _ = 1; _ <= t; _ ++) {
		ld a, b; cin >> a >> b;
		if(a == 0 && b == 0)
			cout << "1\n";
		else if(a == 0)
			cout << "0.5\n";
		else if(b == 0)
			cout << "1\n";
		else if(a / 4 < b)
			cout << 0.5 + a / 4 / 2 / b / 2 << '\n';
		else
			cout << 1 - b * 4 / 2 / a / 2 << '\n';
	}
	return 0;
}