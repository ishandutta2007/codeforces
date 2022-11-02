#include <list>
#include <string>
#include <iostream>
using namespace std;
int n, m, p; string s, t; list<int> x;
int main() {
	cin >> n >> m >> p >> s >> t;
	for (int i = -1; i <= n; i++) x.push_back(i);
	list<int>::iterator it = x.begin();
	for (int i = 0; i < p; i++) it++;
	for (int i = 0; i < m; i++) {
		if (t[i] == 'L') it--;
		if (t[i] == 'R') it++;
		if (t[i] == 'D') {
			if (s[*it] == '(') {
				int d = 1;
				while (true) {
					it = x.erase(it);
					if (*it == n || d == 0) break;
					if (s[*it] == '(') d++;
					else d--;
				}
				if (*it == n) it--;
			}
			else {
				int d = 1;
				while (true) {
					it = x.erase(it); it--;
					if (*it == -1 || d == 0) break;
					if (s[*it] == ')') d++;
					else d--;
				}
				it++;
				if (*it == n) it--;
			}
		}
	}
	it = x.begin();
	while (it != x.end()) {
		if (0 <= *it && *it < n) cout << s[*it];
		it++;
	}
	cout << endl;
	return 0;
}