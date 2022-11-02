#include <bits/stdc++.h>
using namespace std;
long long n;
int main() {
	cin >> n;
	string s = to_string(n); int res = -1; long long ret = -1;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] != '0') {
			string t = s.substr(0, i) + string(1, s[i] - 1) + string(s.size() - i - 1, '9');
			int sum = 0;
			for(int i = 0; i < t.size(); i++) sum += t[i] - 48;
			if(res <= sum) res = sum, ret = stoll(t);
		}
	}
	int x = 0;
	for(int i = 0; i < s.size(); i++) x += s[i] - 48;
	if(x >= res) ret = n;
	cout << ret << endl;
	return 0;
}