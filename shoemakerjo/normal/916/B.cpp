#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	int k;
	cin >> n >> k;
	priority_queue<int, vector<int>, greater<int>> ans;
	map<int, int> ct;
	int m = 0;
	for (int i = -63; i <= 63; i++) {
		ct[i] = 0;
	}
	for (int i = 0; i <= 63; i++) {
		if (n & (1LL << i)) {
			ct[i] = 1;
			m++;
		}
	}
	for (int i = 63; i >= -63; i--) {
		if (m + ct[i] <= k) {
			m += ct[i];
			ct[i-1] += 2*ct[i];
			ct[i] = 0;

		}
		else break;
	}
	for (int i = 63; i >= -63; i--) {
		// cout << i << "  -  " << ct[i] << endl;
		for (int j = 0; j < ct[i]; j++) {
			ans.push(i);
		}
	}
	// cout << "here  " << endl;
	while (ans.size() < k) {
		int cur = ans.top();
		ans.pop();
		ans.push(cur-1);
		ans.push(cur-1);
	}
	if (ans.size() > k) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
		vector<int> pans;
		while (!ans.empty()) {
			pans.push_back(ans.top());
			ans.pop();
		}
		reverse(pans.begin(), pans.end());
		for (int i = 0; i < k; i++) {
			cout << pans[i] << " ";
		}
		cout << endl;

	}
	cin >> n;
}