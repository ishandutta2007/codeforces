#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool isvalid(string s) {
	sort(s.begin(), s.end());
	for (int i = 1; i < s.size(); ++i) {
		if (s[i] == s[i - 1]) return false;
	}
	return true;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	if (n > 26 * 27 / 2) {
		cout << "NO\n";
	}
	else {
		vector<string> ret;
		string cur = s[0];
		s.erase(s.begin());
		while (!s.empty()) {
			bool found = false;
			for (int i = 0; i < s.size() && !found; ++i) {
				if (cur.find(s[i]) != string::npos) {
					s.erase(s.begin() + i);
					found = true;
					break;
				}
				if (s[i].find(cur) != string::npos) {
					cur = s[i];
					s.erase(s.begin() + i);
					found = true;
				}
				for (int j = 1; j < s[i].size() && j < cur.size(); ++j) {
					if (cur.substr(0, j) == s[i].substr(s[i].size() - j)) {
						string cand = s[i].substr(0, s[i].size() - j) + cur;
						if (isvalid(cand)) {
							cur = cand;
							s.erase(s.begin() + i);
							found = true;
						}
						break;
					}
					if (cur.substr(cur.size() - j) == s[i].substr(0, j)) {
						string cand = cur + s[i].substr(j);
						if (isvalid(cand)) {
							cur = cand;
							s.erase(s.begin() + i);
							found = true;
						}
						break;
					}
				}
			}
			if (!found) {
				ret.push_back(cur);
				cur = s[0];
				s.erase(s.begin());
			}
		}
		ret.push_back(cur);
		sort(ret.begin(), ret.end());
		string conc;
		for (string i : ret) {
			conc += i;
		}
		cout << (isvalid(conc) ? conc : "NO") << "\n";
	}
	return 0;
}