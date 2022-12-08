#include <bits/stdc++.h>

using namespace std;

int n;
const int maxn = 5010;

int dp[maxn][maxn][2];
int nums[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}

	for (int d = 1; d <= n; d++) {
		for (int st = 1; st <= n; st++) {
			int en = st + d;
			if (en > n) break;

			dp[st][en][0] = dp[st][en][1] = n+5;

			int cd = 0;
			if (nums[st] != nums[st+1]) cd = 1;
			dp[st][en][0] = min(dp[st][en][0], dp[st+1][en][0]+cd);
			cd = 0;
			if (nums[st] != nums[en]) cd = 1;
			dp[st][en][0] = min(dp[st][en][0], dp[st+1][en][1]+cd);

			cd = 0;
			if (nums[en] != nums[en-1]) cd = 1;
			dp[st][en][1] = min(dp[st][en][1], dp[st][en-1][1]+cd);
			cd = 0;
			if (nums[st] != nums[en]) cd = 1;
			dp[st][en][1] = min(dp[st][en][1], dp[st][en-1][0]+cd);

		}
	}

	cout << min(dp[1][n][0], dp[1][n][1]) << endl;

}