#include <iostream>

using namespace std;

int main() {
	char first, second;
	char f = 94;
	char s = 62, t = 118, fo = 60;
	cin >> first >> second;
	int n;
	cin >> n;
	n = n%4;
	if (n == 0 || n ==2) {
		cout << "undefined" << endl;
	}
	else {
		if (first == f && second == s || first == s && second == t ||
			first == t && second == fo || first == fo && second == f) {
			if (n == 1) {
				cout << "cw" << endl;
			}
			else cout << "ccw" << endl;
		}
		else {
			if (n == 1) {
				cout << "ccw" << endl;
			}
			else cout << "cw" << endl;
		}
	}
	// cin >> n;
}