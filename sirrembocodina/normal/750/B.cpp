#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int x = 10000, y = 0;
	for (int i = 0; i < n; ++i) {
	    if (abs(x) > 10000) {
	        cout << "NO\n";
	        return 0;
	    }
		int  l;
		char s[100];
		cin >> l >> s;
		if (s[0] == 'N') {
			if (x == 10000) {
				cout << "NO\n";
				return 0;
			}
			x += l;
		} else if (s[0] == 'S') {
			if (x == -10000) {
				cout << "NO\n";
				return 0;
			}
			x -= l;
		} else if (s[0] = 'W') {
			if (abs(x) == 10000) {
				cout << "NO\n";
				return 0;
			}
		} else {
			if (abs(x) == 10000) {
				cout << "NO\n";
				return 0;
			}
		}
	}
	if (x != 10000) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
	return 0;
}