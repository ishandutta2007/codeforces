#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
bool palindrome(string t) {
	for (int i = 0; i < t.size(); i++) {
		if (t[i] != t[t.size() - i - 1]) return false;
	}
	return true;
}
string s;
int main() {
	cin >> s;
	bool flag = false;
	for (int i = 0; i < s.size(); i++) {
		for (char j = 'a'; j <= 'z'; j++) {
			if (j == s[i]) continue;
			string t = s; t[i] = j;
			if (palindrome(t)) flag = true;
		}
	}
	cout << (flag ? "YES" : "NO") << endl;
	return 0;
}