#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
int n; string s, t[109];
int main() {
	cin >> s >> n;
	bool f = false;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
		if(s == t[i]) f = true;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (t[i][1] == s[0] && t[j][0] == s[1]) {
				f = true;
			}
		}
	}
	cout << (f ? "YES" : "NO") << endl;
	return 0;
}