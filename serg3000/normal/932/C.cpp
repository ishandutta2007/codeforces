#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int b[9][1000001];
int main() {
	int n, a, b, c = 0, n2;
	cin >> n >> a >> b;
	n2 = n;
	if (n % a == 0) {
		c = n / a;
	}
	else {
		while (n > 0) {
			if ((n % b) != 0) {
				c += 1;
			}
			else {
				break;
			}
			n -= a;
		}
		if (n2 / a + 1 == c) {
			c = -1;
		}
	}
	if (c == -1) {
		cout << -1;
	}
	else {
		int x = 0;
		for (int j = 0; j < c; j++) {
			cout << a + x << " ";
			for (int i = x + 1; i < x + a; i++) {
				cout << i << " ";
			}
			x += a;
		}
		n2 -= c * a;
		int c2 = n2 / b;
		for (int j = 0; j < c2; j++) {
			cout << b + x << " ";
			for (int i = x + 1; i < x + b; i++) {
				cout << i << " ";
			}
			x += b;
		}
	}
	//cout << c;
	return 0;
}