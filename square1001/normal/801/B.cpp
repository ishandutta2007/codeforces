#include <bits/stdc++.h>
using namespace std;
string solve(string s, string t) {
	string ret;
	for(int i = 0; i < s.size(); i++) ret += min(s[i], t[i]);
	return ret;
}
string x, y;
int main() {
	cin >> x >> y;
	if(solve(x, y) != y) cout << -1 << endl;
	else cout << y << endl;
	return 0;
}