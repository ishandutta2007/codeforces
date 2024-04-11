#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int q;
	cin >> q;
	while(q--) {
		string s, t, p;
		cin >> s >> t >> p;
		vector<int> c(26);
		for(int i = 0; i < s.size(); ++i) {
			++c[s[i] - 'a'];
		}
		for(int i = 0; i < p.size(); ++i) {
			++c[p[i] - 'a'];
		}
		for(int i = 0; i < t.size(); ++i) {
			--c[t[i] - 'a'];
		}
		if(*min_element(c.begin(), c.end()) < 0) {
			cout << "NO" << endl;
		}
		else {
			int cur = 0; bool ok = true;
			for(int i = 0; i < s.size(); ++i) {
				while(cur != t.size() && s[i] != t[cur]) ++cur;
				if(cur == t.size()) {
					ok = false;
					break;
				}
				++cur;
			}
			cout << (ok ? "YES" : "NO") << endl;
		}
	}
	return 0;
}