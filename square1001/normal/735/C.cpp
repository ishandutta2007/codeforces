#include <iostream>
#include <algorithm>
using namespace std;
long long n, dp[100];
int main() {
	dp[1] = 2, dp[2] = 3;
	for (int i = 3; i <= 90; i++) dp[i] = dp[i - 1] + dp[i - 2];
	cin >> n;
	for (int i = 1; i <= 90; i++) {
		if (dp[i] > n) {
			cout << i - 1 << endl;
			break;
		}
	}
	return 0;
}