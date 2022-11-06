#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long LL;

int a[105];
bool dp[200005];

int main() {

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	int sum = a[0], g = a[0];
	for (int i = 1; i < n; i++) {
		sum += a[i];
		g = __gcd(g, a[i]);
	}
	sum /= g;
	for (int i = 0; i < n; i++) a[i] /= g;
	if (sum % 2) {
		cout << 0 << endl;
		return 0;
	}
	sum /= 2;
	memset(dp, 0, sizeof dp);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = sum - a[i]; j >= 0; j--) if (dp[j]) dp[j + a[i]] = 1;
	}
	if (!dp[sum]) {
		cout << 0 << endl;
		return 0;
	}
	cout << 1 << endl;
	for (int i = 0; i < n; i++) if (a[i] % 2) {
		cout << i + 1 << endl;
		break;
	}

	return 0;

}