#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int h = 0; h < t; ++h) {
		string s;
		cin >> s;
		int ans = 0;
		for (int i = 0; i < s.size(); ++i) {
			set<char> chars;
			if (i > 0) chars.insert(s[i - 1]);
			if (i > 1) chars.insert(s[i - 2]);
			if (chars.find(s[i]) == chars.end()) continue;
			++ans;
			if (i < s.size() - 2) chars.insert(s[i + 2]);
			if (i < s.size() - 1) chars.insert(s[i + 1]);
			for (char j = 'a'; j <= 'z'; ++j) {
				if (chars.find(j) == chars.end()) {
					s[i] = j;
					break;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}