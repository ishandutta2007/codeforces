#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ans; //stores indices in the string

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int n = s.length();
	set<int> last_one;
	set<int> last_zero;
	bool ok = true;
	for (int i = 0; i < n; i++) {
		// cout << "	" << i << endl;
		if (s[i] == '0') {
			if (last_one.size() != 0) {
				int val = *last_one.begin();
				last_one.erase(last_one.begin());
				ans[val].push_back(i);
				last_zero.insert(val);
			}
			else {
				int val = ans.size();
				vector<int> nv;
				nv.push_back(i);
				ans.push_back(nv);
				last_zero.insert(val);
			}
		}
		if (s[i] == '1') {
			if (last_zero.size() != 0) {
				int val = *last_zero.begin();
				last_zero.erase(last_zero.begin());
				ans[val].push_back(i);
				last_one.insert(val);
			}
			else {
				ok = false;
				break;
			}
		}
	}
	if (last_one.size() != 0) ok = false;
	if (!ok) {
		cout << -1 << endl;
	}
	else {
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i].size();
			for (int j = 0; j < ans[i].size(); j++) {
				cout << " " <<  ans[i][j]+1;
			}
			cout << endl;
		}
	}
	cin >> n;
}