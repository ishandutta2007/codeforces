#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	unordered_map<string, int> seen;
	string cur;
	vector<string> nums;

	for (int i = 0; i < n; i++) {
		cin >> cur;
		unordered_set<string> curs;
		nums.push_back(cur);
		for (int j = 0; j < 9; j++) {
			for (int k = j; k < 9; k++) {
				string temp = cur.substr(j, k-j+1);
				if (curs.find(temp) == curs.end()) {
					curs.insert(temp);
					if (seen.find(temp) == seen.end()) seen[temp] = 1;
					else seen[temp]++;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		string cur = nums[i];
		string ans = " ";
		bool found = false;
		for (int j = 0; j < 9; j++) {
			for (int k = j; k < 9; k++) {
				string temp = cur.substr(j, k-j+1);
				if (seen[temp] == 1) {
					if (!found || temp.length() < ans.length()) {
						found = true;
						ans = temp;
					}
				}
				
			}
		}
		cout << ans << '\n';
	}
	// cin >> n;

}