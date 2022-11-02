#include <bits/stdc++.h>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	int t; cin >> t;
	for(int _ = 1; _ <= t; _ ++) {
		int n; cin >> n;
		cout << max(n - 2, 0) << '\n';
	}
	return 0;
}