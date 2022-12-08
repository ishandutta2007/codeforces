#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int nums[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	vector<int> unseen;
	int pt = 0;
	int ct[n+1];
	int last[n+1];
	bool taken[n+1];
	for (int i = 1; i <= n ;i++) {
		taken[i] = false;
	}
	for (int i = 1; i <= n; i++) {
		ct[i] = 0;
		last[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		ct[nums[i]]++;
		last[nums[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		if (ct[i] == 0) unseen.push_back(i);
	}
	int change = 0;
	for (int i = 0; i < n; i++) {
		if (ct[nums[i]] == 1) continue;
		if (taken[nums[i]]) {
			// cout << "here " << i << endl;
			change++;
			ct[nums[i]]--;
			nums[i] = unseen[pt];
			pt++;
		}
		else {
			if (unseen[pt] < nums[i]) {
				ct[nums[i]]--;
				nums[i] = unseen[pt];
				pt++;
				change++;
			}
			else {
				taken[nums[i]] = true;
			}
		}
	}
	cout << change << '\n';
	for (int i = 0; i < n; i++) {
		if (i > 0) cout << " ";
		cout << nums[i];
	}
	cout << '\n';
	// cin >> n;
}