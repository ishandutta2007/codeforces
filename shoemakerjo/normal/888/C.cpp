#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int ans = 1234567890;
	for (int i = 0; i < 26; i++) {
		int cans = 1;
		int st = 0;
		vector<int> ind;

		for (int j = 0; j < s.length(); j++) {
			if (s[j]-'a' == i) ind.push_back(j);
		}
		if (ind.size() == 0) continue;
		for (int j = 1; j < ind.size(); j++) {
			cans = max(cans, ind[j]-ind[j-1]);
		}
		cans = max(cans, ind[0]+1);
		cans = max(cans, (int) s.length()-ind[ind.size()-1]);
		ans = min(ans, cans);
	}
	cout << ans << endl;
	cin >> ans;
}