#include <string>
#include <iostream>
using namespace std;
int n; string s[1009];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (s[i].find("OO") != string::npos) {
			int ptr = s[i].find("OO");
			s[i][ptr] = s[i][ptr + 1] = '+';
			flag = true;
			break;
		}
	}
	if (!flag) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) cout << s[i] << endl;
	}
	return 0;
}