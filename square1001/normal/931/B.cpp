#include <iostream>
using namespace std;
int n, a, b;
int main() {
	cin >> n >> a >> b; --a, --b;
	for (int i = 2, j = 1; i <= n; i *= 2, ++j) {
		if (a / i == b / i) {
			if (i == n) cout << "Final!" << endl;
			else cout << j << endl;
			break;
		}
	}
	return 0;
}