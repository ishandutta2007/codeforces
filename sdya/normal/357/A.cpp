#include <iostream>
using namespace std;

const int maxN = 110;
int m, c[maxN];
int x, y;

int main() {
	// your code goes here
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> c[i];
	}
	cin >> x >> y;
	for (int i = 1; i <= m; ++i) {
		int a = 0, b = 0;
		for (int j = 1; j < i; ++j) {
			a += c[j];
		}
		for (int j = i; j <= m; ++j) {
			b += c[j];
		}
		if (a >= x && a <= y && b >= x && b <= y) {
			cout << i << endl;
			return 0;
		}
	}
	cout << 0 << endl;
	return 0;
}