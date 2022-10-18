#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n, p;
	cin >> n >> p;
	string s;
	cin >> s;
	for (int i = 0; i < p; i++) {
		string t = "";
		for (int j = i; j < n; j += p) {
			t += s[j];
		}
		int m = t.size();
		if (m == 1) continue;
		int numDots = 0, numOne = 0, numZero = 0;
		for (int j = 0; j < m; j++) {
			numDots += t[j] == '.';
			numOne += t[j] == '1';
			numZero += t[j] == '0';
		}
		if (numDots >= 2) {
			char x = '0';
			for (int j = i; j < n; j += p) {
				if (s[j] == '.') {
					s[j] = x;
					x = '1';
				}
			}
			for (int j = 0; j < n; j++) {
				if (s[j] == '.') {
					s[j] = '1';
				}
			}
			cout << s << endl;
			exit(0);
		}
		if (numDots == 1) {
			for (int j = i; j < n; j += p) {
				if (s[j] == '.') {
					if (numOne == 0) {
						s[j] = '1';
					}
					else if (numZero == 0) {
						s[j] = '0';
					}
					else {
						s[j] = '1';
					}
				}
			}
			for (int j = 0; j < n; j++) {
				if (s[j] == '.') {
					s[j] = '1';
				}
			}
			cout << s << endl;
			exit(0);
		}
		if (numOne > 0 && numZero > 0) {
			for (int j = 0; j < n; j++) {
				if (s[j] == '.') {
					s[j] = '1';
				}
			}
			cout << s << endl;
			exit(0);
		}
	}
	cout << "No" << endl;
	exit(0);
}