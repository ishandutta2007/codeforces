#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> ans;
	for (int i = 2; i <= n; i+=2) {
		ans.push_back(i);
	}
	for (int i = 1; i <= n; i+=2) {
		ans.push_back(i);
	}
	for (int i = 2; i <= n; i+=2) {
		ans.push_back(i);
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		if (i > 0) {
			cout << " ";
		}
		cout << ans[i];
	}
	cout << endl;
	// cin >> n;
}