#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string stRep[8] = {"", "d", "X", "6", "Xd", "X6", "d6", "Xd6"};

bool isValid(string s) {
	bool witha = false, withA = false, with1 = false;
	for (char c : s) {
		if ('a' <= c && c <= 'z') witha = true;
		if ('A' <= c && c <= 'Z') withA = true;
		if ('0' <= c && c <= '9') with1 = true;
	}
	// cout << "result " << witha << withA << with1 << "\n";
	return (witha && withA && with1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while (t--) {
		// stRep = 
		string s; cin >> s;
		string answer;
		for (int tryTo = 0; tryTo < 8; ++tryTo) {
			for (int i = 0; i + stRep[tryTo].size() < s.size(); ++i) {
				for (int k = 0; k < stRep[tryTo].size(); ++k) {
					swap(s[i+k], stRep[tryTo][k]);
				}
				// cout << "testing " << s << "\n";
				if (isValid(s)) {
					answer = s;
				}
				for (int k = 0; k < stRep[tryTo].size(); ++k) {
					swap(s[i+k], stRep[tryTo][k]);
				}
				if (answer.size() > 0) break;
			}
			if (answer.size() > 0) break;
		}
		cout << answer << "\n";
	}
	return 0;
}