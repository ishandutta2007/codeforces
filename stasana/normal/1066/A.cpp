#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef int64_t ll;

int f(int n, int u) {
	return n / u;
}

void solve() {
	int n, u, l, r;
	cin >> n >> u >> l >> r;
	cout << f(l - 1, u) - f(r, u) + f(n, u) << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}