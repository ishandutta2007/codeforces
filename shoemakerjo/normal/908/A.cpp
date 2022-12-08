#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int ct = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '1' || s[i] == '3' || s[i] == '5' || s[i] == '7' ||
			s[i] == '9' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || 
			s[i] == 'o' || s[i] == 'u'){
			ct++;
		}
	}
	cout << ct << endl;
	cin >> ct;
}