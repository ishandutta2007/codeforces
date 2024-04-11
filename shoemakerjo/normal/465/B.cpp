#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int first1 = -1;
	int last1 = -1;
	int n;
	cin >> n;
	int nums[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		if (nums[i] == 1) {
			if (first1 == -1) {
				first1 = i;
			}
			last1 = i;
		}
	}	
	if (first1 == -1) {
		cout << 0 << endl;
		return 0;
	}
	int cur = first1; //cur is actually stupid
	int dp[n+1];
	dp[cur] = 1;
	for (int i = cur; i < last1; i++) { //do not process the last boy
		int nx = i+1;
		while (nums[nx] == 0) nx++;
		dp[nx] = min(dp[i]+2, dp[i] + nx-i);
		i = nx-1;
	}
	cout << dp[last1] << endl;
	cin >> n;

}