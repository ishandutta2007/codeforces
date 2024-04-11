#include <string>
#include <iostream>
using namespace std;
string s;
int main() {
	cin >> s;
	bool flag = true; char c = 'a';
	for (int i = 0; i < s.size(); i++) {
		if (s[i] > c) flag = false;
		if (s[i] == c) c++;
	}
	cout << (flag ? "YES" : "NO") << endl;
	return 0;
}