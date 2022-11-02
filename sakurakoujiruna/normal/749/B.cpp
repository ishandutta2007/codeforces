#include <bits/stdc++.h>
using namespace std;

int main() {
	int x[6], y[6];
	for(int i = 0; i < 3; i ++) {
		cin >> x[i] >> y[i];
		x[i + 3] = x[i];
		y[i + 3] = y[i];
	}
	cout << 3 << '\n';
	for(int i = 0; i < 3; i ++) {
		cout << x[i] + x[i + 1] - x[i + 2] << ' ';
		cout << y[i] + y[i + 1] - y[i + 2] << '\n';
	}
	return 0;
}