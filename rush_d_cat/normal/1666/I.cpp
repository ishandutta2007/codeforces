#include <bits/stdc++.h>
using namespace std;

int query(int x, int y) {
	cout << "SCAN" << " " << x << " " << y << endl;
	int r; cin >> r;
	return r;
}
int main() {
	int t;
	cin >> t;
	while (t --) {
		int n, m;
		cin >> n >> m;

		int v1 = query(1, 1); // x1 - 1 + x2 - 1 + y1 - 1 + y2 - 1
		int v2 = query(n, 1); // x1 - 1 + x2 - 1 + n - y1 + n - y2
		// v1 + v2 = 2*x1 + 2*x2 - 6 + 2n
		int x12 = (v1+v2+6-2*n) / 2;
		int y12 = v1 + 4 - x12;
		
		int v3 = query(y12 / 2, x12 / 2); // x2 - x1 + y2 - y1
		int v4 = query(1, x12 / 2);       // x2 - x1 + y1 - 1 + y2 - 1
		// v4 - v3 = 2*y1 - 2

		int y_1 = (v4 - v3 + 2) / 2;
		int y_2 = y12 - y_1;
		int x_1 = (x12 - (v3 + y_1 - y_2)) / 2;
		int x_2 = x12 - x_1;

		cout << "DIG " << y_1 << " " << x_1 << endl;
		int res; cin >> res;
		if (res) {
			cout << "DIG " << y_2 << " " << x_2 << endl;
			cin >> res;
		} else {
			cout << "DIG " << y_1 << " " << x_2 << endl;
			cin >> res;
			cout << "DIG " << y_2 << " " << x_1 << endl;
			cin >> res;
		}
	}
}