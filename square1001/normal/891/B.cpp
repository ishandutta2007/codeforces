#include <iostream>
using namespace std;
int n, a[22], b[22];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i] > a[j]) b[i]++;
		}
	}
	for (int i = 0; i < n; i++) {
		int pos = -1;
		for (int j = 0; j < n; j++) {
			if (b[j] == (b[i] + 1) % n) pos = j;
		}
		cout << a[pos] << ' ';
	}
	return 0;
}