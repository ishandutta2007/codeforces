#include <vector>
#include <iostream>
using namespace std;
int n, k;
int main() {
	cin >> n >> k; k = 240 - k;
	for (int i = 1; i <= n; i++) {
		k -= 5 * i;
		if (k < 0) {
			cout << i - 1 << endl;
			break;
		}
	}
	if (k >= 0) cout << n << endl;
	return 0;
}