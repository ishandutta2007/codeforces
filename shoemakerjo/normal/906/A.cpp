#include <bits/stdc++.h>

using namespace std;

int main() {
	bool poss[26];
	string alph = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < 26; i++) {
		poss[i] = true;
	}
	int n;
	cin >> n;
	string tp;
	string w;
	int ans = 0;
	bool done = false;
		bool cur[26];
	for (int i = 0; i < n; i++) {
		cin >> tp >> w;
		if (tp == ".") {
			
			for (int j = 0; j < w.length(); j++) {
				poss[w[j]-'a'] = false;
			}
		}
		if (tp == "?") {
			if (i == n-1) continue;
			if (done) ans++;
			poss[w[0]-'a'] = false;
		}
		if (tp == "!") {
			if (done) ans++;		
			for (int j = 0; j < 26; j++) {
				cur[j] = false;
			}
			for (int j = 0; j < w.length(); j++) {
				cur[w[j]-'a'] = true;
			}
			for (int j = 0; j < 26; j++) {
				if (!cur[j]) {
					poss[j] = false;
				}
			}
		}
		int tot = 0;
		for (int i = 0; i < 26; i++) {
			if (poss[i]) {
				tot++;
			}
		}
		if (tot == 1) {
			done = true;
		}
	}
	cout << ans << endl;
	cin >> ans;
}