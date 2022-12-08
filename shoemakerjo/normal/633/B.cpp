#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> m;
	vector<int> ans;
	for (int i = 1; i <= 5*(m+1); i++) {
		int ct = i/5 + i/25 + i/125 + i/625 + i/3125 + i/15625 + i/78125 + i/390625;
		if (ct == m) {
			ans.push_back(i);
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	cin >> m;
}