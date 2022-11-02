#include <string>
#include <iostream>
using namespace std;
int main() {
	int n;
	string s;
	cin >> n >> s;
	int bit = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'L') {
			for (int j = 0; j < 10; ++j) {
				if (!((bit >> j) & 1)) {
					bit |= 1 << j;
					break;
				}
			}
		}
		else if (s[i] == 'R') {
			for (int j = 9; j >= 0; --j) {
				if (!((bit >> j) & 1)) {
					bit |= 1 << j;
					break;
				}
			}
		}
		else {
			bit &= ~(1 << (s[i] - '0'));
		}
	}
	for (int i = 0; i < 10; ++i) {
		cout << ((bit >> i) & 1);
	}
	cout << endl;
	return 0;
}