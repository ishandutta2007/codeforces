#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> nums;
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		nums.push_back(cur);
	}
	sort(nums.begin(), nums.end());
	deque<int> dq;
	for (int i = 0; i < n; i++) {
		dq.push_back(nums[i]);
	}
	int cv = 0;
	while (dq.size() > 1) {
		cv++;
		if (cv & 1) {
			dq.pop_back();
		}
		else dq.pop_front();
	}
	cout << dq.front() << endl;
	cin >> n;
}