#include <string>
#include <iostream>
using namespace std;
int n, a[100009];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	int l = n;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == 1) {
			l = n - i - 1;
			break;
		}
	}
	if (l == 0) cout << "NO" << endl;
	else if (l == 2) {
		int p = -1;
		for (int i = n - 3; i >= 0; i--) {
			if (a[i] == 0) {
				p = i;
				break;
			}
		}
		if (p == -1) cout << "NO" << endl;
		else {
			int q = -1;
			for (int i = p; i >= 0; i--) {
				if (a[i] == 1) {
					q = i; break;
				}
			}
			q++;
			cout << "YES" << endl;
			for (int i = 0; i < q; i++) cout << a[i] << "->";
			cout << "(";
			for (int i = q; i < n - 2; i++) cout << "(" << a[i] << "->";
			cout << 0;
			for (int i = q; i < n - 2; i++) cout << ")";
			cout << "->" << 0 << ")";
		}
	}
	else {
		cout << "YES" << endl;
		for (int i = 0; i < n - l; i++) cout << a[i] << "->";
		for (int i = n - l; i < n - 2; i++) cout << "(" << 0 << "->";
		cout << 0;
		for (int i = n - l; i < n - 2; i++) cout << ")";
		if (l >= 3) cout << "->" << 0;
	}
	return 0;
}