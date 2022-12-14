#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		string s;
		cin >> s;
		int lptr = 0, rptr = s.size() - 1;
		while (lptr < rptr && s[lptr] == s[rptr]) ++lptr, --rptr;
		if (lptr >= rptr) {
			cout << s << '\n';
			continue;
		}
		int l = rptr, r = lptr;
		for (; l >= lptr; --l) {
			bool works = true;
			for (int j = lptr, k = l; j < k; ++j, --k) {
				if (s[j] != s[k]) {
					works = false;
					break;
				}
			}
			if (works) break;
		}
		for (; r <= rptr; ++r) {
			bool works = true;
			for (int j = r, k = rptr; j < k; ++j, --k) {
				if (s[j] != s[k]) {
					works = false;
					break;
				}
			}
			if (works) break;
		}
		if (l - lptr >= rptr - r) {
			for (int i = 0; i <= l; ++i) cout << s[i];
			for (int i = rptr + 1; i < s.size(); ++i) cout << s[i];
		} else {
			for (int i = 0; i < lptr; ++i) cout << s[i];
			for (int i = r; i < s.size(); ++i) cout << s[i];
		}
		cout << endl;
	}
	return 0;
}