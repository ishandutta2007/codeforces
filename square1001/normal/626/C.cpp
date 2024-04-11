#include <iostream>
#include <algorithm>
using namespace std;
int a, b;
int main() {
	cin >> a >> b;
	for (int i = 0; ; i++) {
		if (max(a - i / 2 + i / 6, 0) + max(b - i / 3 + i / 6, 0) <= i / 6) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}