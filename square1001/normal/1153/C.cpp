#include <string>
#include <iostream>
using namespace std;
int main() {
	int n; string s;
	cin >> n >> s;
	if (n % 2 == 1) {
		cout << ":(" << endl;
	}
	else {
		int ru = n / 2, rd = n / 2;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '(') --ru;
			if (s[i] == ')') --rd;
		}
		if (ru < 0 || rd < 0) {
			cout << ":(" << endl;
		}
		else {
			for (int i = 0; i < n; ++i) {
				if (s[i] != '?') continue;
				if (ru > 0) s[i] = '(', --ru;
				else s[i] = ')', --rd;
			}
			int depth = 0;
			bool ok = true;
			for (int i = 0; i < n - 1 && ok; ++i) {
				if (s[i] == '(') ++depth;
				else --depth;
				if (depth <= 0) ok = false;
			}
			cout << (ok ? s : ":(") << endl;
		}
	}
	return 0;
}