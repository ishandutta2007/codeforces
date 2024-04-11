#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	vector<bool> mightBeLetter(26, true);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		string temp, word; cin >> temp >> word;
		char type = temp[0];
		int candidates = 0;
		for (bool x : mightBeLetter) {
			candidates += x;
		}
		if (candidates == 1) {
			// we've figured it out! this is excessive
			if (type == '!' || (type == '?' && i < n - 1)) {
				++ans;
			}
		} else {
			// let's figure this out
			if (type == '?' && i < n - 1) {
				int guess = word[0] - 'a';
				mightBeLetter[guess] = false;
			}
			if (type == '.') {
				for (char c : word) {
					mightBeLetter[c - 'a'] = false;
				}
			}
			if (type == '!') {
				vector<bool> isInGuess(26, false);
				for (char c : word) {
					isInGuess[c - 'a'] = true;
				}
				for (int i = 0; i < 26; ++i) {
					if (!isInGuess[i]) {
						mightBeLetter[i] = false;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}