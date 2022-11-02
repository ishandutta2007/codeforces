#include <bits/stdc++.h>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	int t; cin >> t;
	string s; cin >> s;
	if(s[3] >= '6')
			s[3] = '0';
	int h = atoi(s.substr(0, 2).c_str());
	if(t == 12) {
		if(h == 0)
			s[0] = '1';
		else if(h > 12) {
			if(s[1] == '0')
				s[0] = '1';
			else
				s[0] = '0';
		}
	} else if(h > 23)
		s[0] = '0';
	cout << s << '\n';
	return 0;
}