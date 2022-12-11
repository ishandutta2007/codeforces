#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

void start() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
}

int main() {
	start();
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 1; i < n; ++i) {
		if (s[i - 1] == s[i] && s[i] != '?') {
			cout << "No";
			return 0;
		}
	}
	s = "?" + s + "?";
	for (int i = 1; i < s.length(); ++i) {
		if (s[i] == s[i - 1] && s[i] == '?') {
			cout << "Yes";
			return 0;
		}
	}
	for (int i = 1; i < s.length() - 1; ++i) {
		if (s[i] == '?' && s[i - 1] == s[i + 1]) {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}