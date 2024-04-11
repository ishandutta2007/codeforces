#include <string>
#include <iostream>
using namespace std;
string s;
int main() {
	cin >> s;
	for (int i = 1; i < s.size(); i++) {
		if (s[i - 1] == s[i]) {
			for (char j = 'a'; j <= 'z'; j++) {
				if (s[i] == j) continue;
				if (i + 1 == s.size() || s[i + 1] != j) {
					s[i] = j;
					break;
				}
			}
		}
	}
	cout << s << endl;
	return 0;
}