#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a = 0, b = 0;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		if (v == 0) {
			++a;
		} else {
			++b;
		}
	}
	if (a == 0) {
		cout << -1 << endl;
		return 0;
	}
	int t = 0;
	for (int k = b; k >= 0; --k) {
		if (k % 9 == 0) {
			t = k;
			break;
		}
	}
	if (t == 0) {
		cout << 0 << endl;
	} else {
		for (int i = 0; i < t; ++i) {
			cout << 5;
		}
		for (int i = 0; i < a; ++i) {
			cout << 0;
		}
		cout << endl;
	}
	return 0;
}