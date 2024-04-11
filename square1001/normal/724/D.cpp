#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int m; string s;
	cin >> m >> s;
	int n = s.size();
	vector<int> cat = { -1, n };
	string ans;
	for(char c = 'a'; c <= 'z'; ++c) {
		vector<int> ncat = cat;
		for(int i = 0; i < n; ++i) {
			if(s[i] == c) ncat.push_back(i);
		}
		sort(ncat.begin(), ncat.end());
		bool ok = true;
		for(int j = 1; j < ncat.size(); ++j) {
			if(ncat[j] - ncat[j - 1] > m) ok = false;
		}
		if(ok) {
			for(int i : cat) {
				if(0 <= i && i < n) ans += s[i];
			}
			sort(ans.begin(), ans.end());
			for(int i = 1; i < cat.size(); ++i) {
				vector<int> subvec = { -1 };
				for(int j = cat[i - 1] + 1; j < cat[i]; ++j) {
					if(s[j] == c) subvec.push_back(j - cat[i - 1] - 1);
				}
				subvec.push_back(cat[i] - cat[i - 1] - 1);
				int ptr = 0;
				while(ptr + 1 != subvec.size()) {
					ptr = lower_bound(subvec.begin(), subvec.end(), subvec[ptr] + m + 1) - subvec.begin() - 1;
					if(ptr + 1 != subvec.size()) ans += c;
				}
			}
			break;
		}
		else cat = ncat;
	}
	cout << ans << endl;
	return 0;
}