#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string good;
	cin >> good;
	bool ok[26];
	for (int i = 0; i < 26; i++) {
		ok[i] = false;
	}
	for (int i = 0; i  < good.length(); i++) {
		ok[good[i]-'a'] = true;
	}
	string pattern;
	cin >> pattern;
	bool hasstar = false;
	for (int i = 0; i < pattern.length(); i++) {
		if (pattern[i]=='*') hasstar = true; 
	}
	string cur;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		int starlen = cur.length()-pattern.length();
		if (hasstar) starlen++;
		bool valid = true;
		if (cur.length()+1 == pattern.length()) starlen = 0;
		if (hasstar && pattern.length()-1 > cur.length()) valid = false;
		else if (!hasstar && (cur.length() != pattern.length())) valid = false;
		else {
			int pt = 0;
			for (int j = 0; j < cur.length(); j++) {
				if (pattern[pt]=='*') {
					for (int k = 0; k < starlen; k++) {
						if (ok[cur[k+j]-'a']) {
							valid = false;
							// cout << "pt: " << k+j << endl;
						}
					}
					j =j+starlen-1;
				}
				else if (pattern[pt] == '?') {
					if (!ok[cur[j]-'a']) {
						valid = false;
						// cout << "pt: " << pt << endl;
					}
				}
				else {
					if (!(cur[j]==pattern[pt])) {
						valid = false;
					}
				}
				pt++;
			} 
		}

		if (valid) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	cin >> pattern;
}