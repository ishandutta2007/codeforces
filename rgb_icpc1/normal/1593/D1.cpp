#include <bits/stdc++.h>
#define MX 105

using namespace std;

int n;
int a[MX], gcd1;


int ext_gcd(int a, int b, int& x, int& y) {
	int g;
	if (b) {
		g = ext_gcd(b, a % b, y, x);
		y -= a / b * x;
	}
	else {
		g = a;
		x = 1, y = 0;
	}
	return g;
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		gcd1 = 0;
		int x, y;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (!i) continue;
			if (a[i] == a[0]) continue;
			gcd1 = ext_gcd(gcd1, a[i] - a[0], x, y);
			if (gcd1 < 0) gcd1 = -gcd1;
		}
		if (gcd1 == 0) cout << -1 << endl;
		else cout << gcd1 << endl;
	}
	
}