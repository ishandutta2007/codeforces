#include <bits/stdc++.h>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, A, B;
	cin >> N >> A >> B;
	bool dp[N+1];
	fill(dp, dp+N+1, false);
	dp[0] = true;
	for (int i = 1; i <= N; i++) {
		if (i-A >= 0 && dp[i-A]) dp[i] = true;
		if (i-B >= 0 && dp[i-B]) dp[i] = true;
	}
	int ans[N+1];
	if (!dp[N]) {
		cout << -1 << endl;
	}
	else {
		int cur = N;
		while (cur != 0) {
			if (cur - A >= 0 && dp[cur-A]) {
				for (int i = cur-A+1; i < cur; i++) {
					ans[i] = i+1;
				}
				ans[cur] = cur-A+1;
				cur = cur-A;
			}
			else {
				for (int i = cur-B+1; i < cur; i++) {
					ans[i] = i+1;
				}
				ans[cur] = cur-B+1;
				cur = cur-B;
			}
		}
		for (int i = 1; i <= N; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	cin >> N;
	

}