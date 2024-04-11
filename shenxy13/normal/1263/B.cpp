#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int main() {
	int t, n;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> n;
		string s[n];
		set<string> a;
		set<char> b;
		set<int> prob;
		for (int j = 0; j < n; ++j) {
			cin >> s[j];
			if (a.find(s[j]) == a.end()) {
				a.insert(s[j]);
				b.insert(s[j][0]);
			} else prob.insert(j);
		}
		for (int j: prob) {
			for (char c = '0'; c <= '9'; ++c) {
				if (b.find(c) == b.end()) {
					s[j][0] = c;
					b.insert(c);
					break;
				}
			}
		}
		cout << prob.size() << "\n";
		for (int j = 0; j < n; ++j) cout << s[j] << "\n";
	}
	return 0;
}