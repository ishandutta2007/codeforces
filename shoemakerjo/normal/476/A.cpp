#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	bool found  = false;
	for (int i = (n+1)/2; i <= n; ++i) {
		if (i % m == 0) {
			cout << i << endl;
			found = true;
			break;
		}
	}
	if (!found) cout << -1 << endl;
}