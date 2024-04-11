#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, r, c;
		cin >> n >> m >> r >> c;
		cout << max({ r + c - 2, n - r + c - 1, m - c + r - 1, m - c + n - r }) << "\n";
	}
	return 0;
}