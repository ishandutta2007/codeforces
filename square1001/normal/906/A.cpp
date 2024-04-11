#include <string>
#include <iostream>
using namespace std;
int n; string tp, s;
int main() {
	cin >> n;
	int bit = (1 << 26) - 1, ret = 0;
	for (int i = 0; i < n; i++) {
		cin >> tp >> s;
		if (i != n - 1 && (bit & (bit - 1)) == 0 && tp != ".") ret++;
		if (tp == "?") {
			if (i != n - 1) bit &= ~(1 << (s[0] - 'a'));
		}
		if (tp == ".") {
			for (int j = 0; j < s.size(); j++) {
				bit &= ~(1 << (s[j] - 'a'));
			}
		}
		if (tp == "!") {
			int x = 0;
			for (int j = 0; j < s.size(); j++) {
				x |= 1 << (s[j] - 'a');
			}
			bit &= x;
		}
	}
	cout << ret << endl;
	return 0;
}