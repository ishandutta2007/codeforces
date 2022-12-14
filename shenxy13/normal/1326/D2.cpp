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
		if (lptr >= rptr) cout << s;
		else {
			string t = s.substr(lptr, rptr - lptr + 1), u = t;
			reverse(u.begin(), u.end());
			string concat = t + "." + u;
			int nxt[concat.size()];
			for (int i = 0, ptr = -1; i < concat.size(); ptr = nxt[i], ++i) {
				while (ptr > -1 && concat[ptr + 1] != concat[i]) ptr = nxt[ptr];
				nxt[i] = i > 0 && concat[ptr + 1] == concat[i] ? ptr + 1 : -1;
			}
			int nxt2[concat.size()];
			string concat2 = u + "." + t;
			for (int i = 0, ptr = -1; i < concat.size(); ptr = nxt2[i], ++i) {
				while (ptr > -1 && concat2[ptr + 1] != concat2[i]) ptr = nxt2[ptr];
				nxt2[i] = i > 0 && concat2[ptr + 1] == concat2[i] ? ptr + 1 : -1;
			}
			if (nxt2[concat.size() - 1] >= nxt[concat.size() - 1]) {
				for (int j = 0; j < lptr; ++j) cout << s[j];
				for (int j = rptr - nxt2[concat.size() - 1]; j < s.size(); ++j) cout << s[j];
			} else {
				for (int j = 0; j <= lptr + nxt[concat.size() - 1]; ++j) cout << s[j];
				for (int j = rptr + 1; j < s.size(); ++j) cout << s[j];
			}
		}
		cout << endl;
	}
	return 0;
}