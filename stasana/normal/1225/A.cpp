#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

inline void start() {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
}

inline void solve() {
	int a, b;
	cin >> a >> b;
	if (a == b) {
		cout << a * 10 << " " << b * 10 + 1 << endl;
		return;
	}
	if (a == 9 && b == 1) {
		cout << 9 << " " << 10 << endl;
		return;
	}
	if (a + 1 == b) {
		cout << a << " " << b << endl;
		return;
	}
	cout << -1 << endl;
}

int main() {
	start();
	solve();
	return 0;
}