#include <iostream>
using namespace std;
int n, m; long long x;
int main() {
	cin >> n >> m >> x;
	if (x < n) cout << x + 1 << " 1" << endl;
	else {
		x -= n;
		int row = n - x / (m - 1), col = x % (m - 1);
		if (row % 2 == 1) col = m - col - 2;
		cout << row << ' ' << col + 2 << endl;
	}
	return 0;
}