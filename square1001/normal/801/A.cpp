#include <bits/stdc++.h>
using namespace std;
int solve(string s) {
	int ret = 0;
	for(int i = 1; i < s.size(); i++) {
		ret += (s[i - 1] == 'V' && s[i] == 'K');
	}
	return ret;
}
string t;
int main() {
	cin >> t;
	int ret = 0;
	for(int i = 0; i < t.size(); i++) {
		for(char j = 'A'; j <= 'Z'; j++) {
			string u = t; u[i] = j;
			ret = max(ret, solve(u));
		}
	}
	cout << ret << endl;
	return 0;
}