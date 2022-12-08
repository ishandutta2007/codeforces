#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	set<char> allow;
	for (int i = 0; i < s.length(); i++) {
		allow.insert(s[i]);
	}
	auto it = allow.begin();
	vector<char> vals;
	while (it != allow.end()) {
		vals.push_back(*it);
		++it;
	}
	//k is answer
	if (k > n) {
		cout << s;
		for (int i = 0; i < k-n; i++) {
			cout << vals[0];
		}
		cout << endl;
	}
	else {
		string ans = s;
		for (int i = k-1; i >= 0; i--) {
			if (s[i] != vals[vals.size()-1]) {
				for (int j = 0; j < vals.size(); j++) {
					if (s[i] == vals[j]) {
						ans[i] = vals[j+1];
						break;
					}
				}
				break;
			}
			else {
				ans[i] = vals[0];
			}
		}
		cout << ans.substr(0, k) << endl;
	}
	cin >> n;
}