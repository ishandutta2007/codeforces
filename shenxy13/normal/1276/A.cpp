#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	string s;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		vector<int> ans;
		cin >> s;
		for (int j = 2; j < s.size(); ++j) {
			if (s[j - 2] == 'o' && s[j - 1] == 'n' && s[j] == 'e') ans.push_back(j);
			else if (s[j - 2] == 't' && s[j - 1] == 'w' && s[j] == 'o') {
				if (j + 2 < s.size() && s[j + 1] == 'n' && s[j + 2] == 'e') ans.push_back(j + 1), j += 2;
				else ans.push_back(j);
			}
		}
		printf("%lu\n", ans.size());
		for (int j = 0; j < (int) ans.size() - 1; ++j) printf("%d ", ans[j]);
		if (ans.size() != 0) printf("%d\n", ans.back());
		else printf("\n");
	}
	return 0;
}