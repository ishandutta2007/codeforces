#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
int solve(string s, string t) {
	for (int i = 0; i < s.size() && i < t.size(); i++) {
		if (s[i] != t[i]) return i;
	}
	return min(s.size(), t.size());
}
int n; string s[555555];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i], s[i] += '$';
	for (int i = n - 2; i >= 0; i--) {
		int z = solve(s[i], s[i + 1]);
		if (s[i].size() != z && s[i][z] > s[i + 1][z]) {
			s[i] = s[i].substr(0, z);
		}
	}
	for (int i = 0; i < n; i++) {
		if (s[i].back() == '$') s[i].pop_back();
		cout << s[i] << endl;
	}
	return 0;
}