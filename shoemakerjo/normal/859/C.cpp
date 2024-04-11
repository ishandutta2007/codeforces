#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	int pie[N];
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> pie[i];
		sum += pie[i];
	}
	int suff[N];
	suff[N-1] = pie[N-1];
	for (int i = N-2; i >= 0; i--) {
		suff[i] = suff[i+1] + pie[i];
	}
	int dp[N];
	dp[N-1] = pie[N-1];
	for (int i = N-2; i >= 0; i--) {
		dp[i] = max(pie[i] + suff[i+1]-dp[i+1], dp[i+1]);
	}
	cout << sum-dp[0] << " " << dp[0] << endl;
	// cin >> N;

}