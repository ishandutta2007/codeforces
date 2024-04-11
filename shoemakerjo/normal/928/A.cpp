#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int n;
	cin >> n;
	string logins[n];
	for (int i = 0; i < n; i++) {
		cin >> logins[i];
	}
	string alph = "abcdefghijklmnopqrstuvwxyz";
	string ALPH = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	map<char, vector<char>> same;
	for (int i = 0; i < 26; i++) {
		vector<char> nc;
		nc.push_back(ALPH[i]);
		same[alph[i]] = nc;
		vector<char> nc2;
		nc2.push_back(alph[i]);
		same[ALPH[i]] = nc2;
	}
	same['O'].push_back('0');
	same['o'].push_back('0');
	same['0'].push_back('o');
	same['0'].push_back('O');
	same['1'].push_back('l');
	same['1'].push_back('L');
	same['1'].push_back('i');
	same['1'].push_back('I');
	same['l'].push_back('1');
	same['L'].push_back('1');
	same['i'].push_back('1');
	same['I'].push_back('1');
	same['l'].push_back('I');
	same['l'].push_back('i');
	same['L'].push_back('I');
	same['L'].push_back('i');
	same['i'].push_back('l');
	same['i'].push_back('L');
	same['I'].push_back('l');
	same['I'].push_back('L');
	bool ans = false;
	for (int i = 0; i < n; i++) {
		if (logins[i].length() != s.length()) continue;
		bool ok = true;
		for (int j = 0; j < s.length(); j++) {
			bool foun = false;
			if (s[j] == logins[i][j]) foun = true;
			if (same.count(s[j]) > 0) {
				for (int k = 0; k < same[s[j]].size(); k++) {
					if (logins[i][j] == same[s[j]][k]) foun = true;
				}
			}
			
			if (!foun) ok = false;
		}
		ans = ans || ok;
	}
	if (ans) cout << "No" << endl;
	else cout << "Yes" << endl;
	cin >> n;
}