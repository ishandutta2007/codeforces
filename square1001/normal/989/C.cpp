#include <iostream>
using namespace std;
int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << "40 40\n";
	for (int i = 0; i < 40; ++i) {
		for (int j = 0; j < 40; ++j) {
			cout << (i < 20 ? (j < 20 ? ((i & 1) && (j & 1) && --d > 0 ? 'D' : 'A') : ((i & 1) && (j & 1) && --c > 0 ? 'C' : 'B')) : (j < 20 ? ((i & 1) && (j & 1) && --b > 0 ? 'B' : 'C') : ((i & 1) && (j & 1) && --a > 0 ? 'A' : 'D')));
		}
		cout << '\n';
	}
	return 0;
}