#include <iostream>
#include <algorithm>
#include <cstring>

#define fs first
#define sc second

using namespace std;

int a[100], b[100];

int main() {
	int t;
	cin >> t;
	for (int q = 0; q < t; ++q) {
		int n, m;
		cin >> n;
		m = n / 2 + n % 2;
		for (int i = 0; i < m; ++i) {
			if (2 * i + 1 < n) {
				cout << "? " << 2 * i + 1 << " " << 2 * i + 2 << endl;
				cout.flush();
				char tmp[10];
				cin >> tmp;
				if (tmp[0] == '<') {
					a[i] = 2 * i;
					b[i] = 2 * i + 1;
				} else {
					a[i] = 2 * i + 1;
					b[i] = 2 * i;
				}
			} else {
				a[i] = b[i] = 2 * i;
			}
		}
		int mn = a[0], mx = b[0];
		for (int i = 0; i < m - 1; ++i) {
			cout << "? " << mn + 1 << " " << a[i + 1] + 1 << endl;
			cout.flush();
			char tmp[10];
			cin >> tmp;
			if (tmp[0] == '>') {
				mn = a[i + 1];
			}
		}
		for (int i = 0; i < m - 1; ++i) {
			cout << "? " << mx + 1 << " " << b[i + 1] + 1 << endl;
			cout.flush();
			char tmp[10];
			cin >> tmp;
			if (tmp[0] == '<') {
				mx = b[i + 1];
			}
		}
		cout << "! " << mn + 1 << " " << mx + 1 << endl;
	}
}