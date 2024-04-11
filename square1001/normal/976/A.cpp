#include <string>
#include <iostream>
using namespace std;
int n; string s;
int main() {
	cin >> n >> s;
	if (s == "0") cout << "0" << endl;
	else {
		int cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '0') cnt++;
		}
		cout << '1' << string(cnt, '0') << endl;
	}
	return 0;
}