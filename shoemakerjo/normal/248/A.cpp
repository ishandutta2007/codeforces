#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int lo = 0, ro = 0;
	int l, r;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		lo+=l;
		ro+=r;
	}
	int ans = min(lo, n-lo) + min(ro, n-ro);
	cout << ans << endl;
	cin >> n;
}