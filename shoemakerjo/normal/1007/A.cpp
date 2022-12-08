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
	
	priority_queue<int, vector<int>, greater<int>> pq;
	int ans = 0;
	for (int i = 0; i < nums.size(); i++) {
		pq.push(nums[i]);
		if (pq.top() < nums[i]) {
			ans++;
			pq.pop();
		}
	}



	cout << ans << endl;
}