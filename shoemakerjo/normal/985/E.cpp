#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, d;
	cin >> n >> k >> d;
	vector<int> nums;
	int ch[n+2];
	fill(ch, ch+n+2, 0);
	ch[0] = 1;
	ch[1] = -1;
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		nums.push_back(cur);
	}
	sort(nums.begin(), nums.end());
	int cv = 0;
	bool ans = false;
	for (int i = 0; i < n; i++) {
		cv += ch[i];
		int nx = i+k-1;
		if (cv <= 0) continue; //can't start with this
		if (nx >= n) break; //too far
		if (nums[nx]-nums[i] > d) continue; //this won't work anyway
		int ind = upper_bound(nums.begin(), nums.end(), nums[i]+d) - nums.begin() - 1;
		ch[nx+1]++; //works to start with this
		ch[ind+2]--;
		if (ind+1 >= n) ans = true;
	}

	if (ans) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
	cin >> n;
}