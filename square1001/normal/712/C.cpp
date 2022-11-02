#include <iostream>
#include <algorithm>
using namespace std;
int x, y, a[3];
int main() {
	cin >> x >> y;
	a[0] = a[1] = a[2] = y;
	for (int i = 1; ; i++) {
		int ptr = min_element(a, a + 3) - a;
		int p = a[(ptr + 1) % 3];
		int q = a[(ptr + 2) % 3];
		a[ptr] = min(x, p + q - 1);
		if (a[ptr] == x && p == x && q == x) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}