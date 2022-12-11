#include <bits/stdc++.h>
using namespace std;

bool check(int k1, int k2, int w) {
	return (k1 + k2 >> 1) >= w;
}

int main() {
	int T; cin >> T;
	while (T--) {
		int n, k1, k2; cin >> n >> k1 >> k2;
		int w, b; cin >> w >> b;
		cout << (check(k1, k2, w) && check(n - k1, n - k2, b) ? "YES" : "NO") << endl;
	}
	return 0;
}