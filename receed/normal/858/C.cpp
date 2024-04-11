#include <bits/stdc++.h>

using namespace std;

int main() {
	string s, t;
	cin >> s;
	string v = "aeiou ";
	for (int i = 0; i < s.size(); i++) {
		if (t.size() > 1 && v.find(s[i]) == string::npos && v.find(t[t.size() - 1]) == string::npos &&
				v.find(t[t.size() - 2]) == string::npos && (s[i] != t[t.size() - 1] || s[i] != t[t.size() - 2]))
			t += ' ';
		t += s[i];
	}
	cout << t << endl;
}