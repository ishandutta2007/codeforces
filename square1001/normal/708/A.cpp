#include <string>
#include <iostream>
using namespace std;
string s;
int main() {
	cin >> s;
	if (s == string(s.size(), 'a')) cout << string(s.size() - 1, 'a') << "z" << endl;
	else {
		int l = -1, r = s.size();
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != 'a' && l == -1) l = i;
			if (s[i] == 'a' && l != -1 && r == s.size()) r = i;
		}
		for (int i = l; i < r; i++) s[i]--;
		cout << s << endl;
	}
	return 0;
}