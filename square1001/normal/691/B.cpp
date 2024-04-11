#include <bits/stdc++.h>
using namespace std;
bool match(char a) {
	return string("AHIMOoTUVvWwXxY").find(a) != string::npos;
}
bool match(char a, char b) {
	if(a > b) swap(a, b);
	if(a == b && match(a)) return true;
	if(a == 'b' && b == 'd') return true;
	if(a == 'p' && b == 'q') return true;
	return false;
}
string s;
int main() {
	cin >> s;
	bool f = true;
	for(int i = 0; i < s.size(); i++) {
		if(!match(s[i], s[s.size() - i - 1])) f = false;
	}
	cout << (f ? "TAK" : "NIE") << endl;
	return 0;
}