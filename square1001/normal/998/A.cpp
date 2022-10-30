#include <iostream>
using namespace std;
int n, a[109];
int main() {
	cin >> n;
	int s = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		s += a[i];
	}
	int ptr = -1;
	for (int i = 0; i < n; ++i) {
		if (s - a[i] != a[i]) ptr = i;
	}
	if (n == 1 || ptr == -1) cout << -1 << endl;
	else {
		cout << 1 << endl;
		cout << ptr + 1 << endl;
	}
	return 0;
}