#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	int t = unique(s.begin(), s.end()) - s.begin();
	if (t % 2 == 0) {
		cout << "CHAT WITH HER!";
	} else {
		cout << "IGNORE HIM!";
	}
	return 0;
}