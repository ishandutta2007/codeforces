#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool isLucky(int n) {
	if (n == 0) {
		return false;
	}
	while (n) {
		if (n % 10 != 4 && n % 10 != 7) {
			return false;
		}
		n /= 10;
	}
	return true;
}

bool isLucky(string s) {
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] != '4' && s[i] != '7') {
			return false;
		}
	}
	return true;
}

int main() {
	map < string, int > M;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		for (int j = 1; j + i <= s.size(); ++j) {
			if (isLucky(s.substr(i, j))) {
				++M[s.substr(i, j)];
			}
		}
	}
	vector < pair < int, string > > u;
	for (map < string, int > ::iterator it = M.begin(); it != M.end(); ++it) {
		u.push_back(make_pair(-it->second, it->first));
	}
	sort(u.begin(), u.end());
	if (u.size() == 0) {
		cout << -1 << endl;
	} else {
		cout << u[0].second << endl;
	}
	return 0;
}