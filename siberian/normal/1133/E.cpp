#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MAXN = 5010;
int dp[MAXN][MAXN];
int n, k;
vector <int> arr;
void read() {
	cin >> n >> k;
	arr.resize(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
}

void run() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = dp[i - 1][j];
			int pos = lower_bound(arr.begin(), arr.end(), arr[i] - 5) - arr.begin();
			pos = max(pos, 1LL);
			dp[i][j] = max(dp[i][j], dp[pos - 1][j - 1] + i - pos + 1);
		}
	}
}

void write() {
	int ans = 1;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= k; j++)
			ans = max(ans, dp[i][j]);
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}