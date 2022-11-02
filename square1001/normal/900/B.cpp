#include <iostream>
using namespace std;
int a, b, c;
int main() {
	cin >> a >> b >> c;
	bool found = false;
	for (int i = 1; i <= 100000; ++i) {
		a *= 10;
		if (a / b == c) {
			cout << i << '\n';
			found = true;
			break;
		}
		a %= b;
	}
	if (!found) cout << "-1\n";
	return 0;
}