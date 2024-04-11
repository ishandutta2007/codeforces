#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("C.in", "r", stdin);
	//freopen("C.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	vector <vector <ll> > dp(n + 1, vector <ll> (2, 0));
	for (int i = 0; i < n; i++) {
		dp[i + 1][0] = max(dp[i][0], dp[i][1] + a[i]);
		dp[i + 1][1] = max(dp[i][1], dp[i][0] + b[i]);
	} 
	cout << max(dp[n][0], dp[n][1]);
}