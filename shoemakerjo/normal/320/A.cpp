#include <iostream>
#include <string>
using namespace std;

int main() {
	bool good = true;
	string s;
	cin >> s;
	int cur = 4;
	for (int i = 0; i < s.length(); i++) {
		if (s[i]!='4' && s[i]!='1') good = false;
		if (s[i] == '4') {
			cur++;
			if (cur > 2) good = false;
		}
		if (s[i]=='1') cur = 0;
	}
	if (good) cout << "YES" << endl;
	else cout << "NO" << endl;
	// cin >> s;

}