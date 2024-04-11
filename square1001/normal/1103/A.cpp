#include <string>
#include <iostream>
using namespace std;
int main() {
	string s;
	cin >> s;
	int vc = 0, hc = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '0') cout << 1 << ' ' << hc % 4 + 1 << endl, ++hc;
		else cout << 3 << ' ' << vc % 2 * 2 + 1 << endl, ++vc;
	}
	return 0;
}