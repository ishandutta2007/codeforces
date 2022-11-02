#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
string s;
int main() {
	cin >> s;
	int p1 = 0, p2 = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '.') p1 = i;
		if (s[i] == 'e') p2 = i;
	}
	string a = s.substr(0, p1);
	string b = s.substr(p1 + 1, p2 - p1 - 1);
	string c = s.substr(p2 + 1);
	if (b == "0") b = "";
	int pos = a.size() + stoi(c); a += b;
	while (pos > a.size()) a += '0';
	while (pos >= 2 && a[0] == '0') a.erase(a.begin()), pos--;
	if (pos == a.size()) cout << a << endl;
	else cout << a.substr(0, pos) << '.' << a.substr(pos) << endl;
	return 0;
}