#include <string>
#include <iostream>
using namespace std;
string s;
int main() {
	cin >> s;
	int h = (s[0] - 48) * 10 + (s[1] - 48), m = (s[3] - 48) * 10 + (s[4] - 48);
	for (int i = 0; ; i++) {
		int rh = (h * 60 + m + i) / 60 % 24, rm = (h * 60 + m + i) % 60;
		string sh = to_string(rh); if (sh.size() == 1) sh = "0" + sh;
		string sm = to_string(rm); if (sm.size() == 1) sm = "0" + sm;
		if (sh[0] == sm[1] && sh[1] == sm[0]) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}