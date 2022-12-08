#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int low = max(1, n-81);
	vector<int> ans;
	for (int i = low; i <= n; i++) {
		int sum = 0;
		sum += i;
		int cur = i;
		while (cur > 0) {
			sum += cur%10;
			cur/=10;
		}
		if (sum == n) {
			ans.push_back(i);
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
	// cin >> n;
}