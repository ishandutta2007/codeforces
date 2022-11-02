#include <vector>
#include <iostream>
using namespace std;
int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	if ((n - 1) % m == 1) cout << (n + m - 2) / m * 2 - 1 << endl;
	else cout << (n + m - 2) / m * 2 << endl;
	for (int i = 0; i < m; i++) {
		int l = 1LL * i * (n - 1) / m, r = 1LL * (i + 1) * (n - 1) / m;
		cout << 1 << ' ' << l + 2 << endl;
		for (int i = l + 1; i < r; i++) cout << i + 1 << ' ' << i + 2 << endl;
	}
	return 0;
}