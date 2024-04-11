#include <bits/stdc++.h>

using namespace std;

int gcd(int u, int v) {
	if (u%v == 0) return v;
	if (v%u==0) return u;
	// if (u == v) return u;
	if (u > v) {
		return gcd(u%v, v);
	}
	return gcd(u, v%u);
}

int main() {
	int n;
	cin >> n;
	int ans = 1;
	for (int i = 2; i+i < n; i++) {
		if (gcd(i, n-i) == 1) ans = i;
	}
	cout << ans << " " << n-ans << endl;
	cin >> ans;
}