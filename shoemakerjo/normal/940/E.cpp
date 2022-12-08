#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, c;
	cin >> n >> c;
	ll a[n+1]; 
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	ll dp[n+1];
	dp[0] = 0;
	multiset<ll> curin; //values currently in the last c
	ll csum = 0LL;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i-1] + a[i]; //just take one value
		curin.insert(a[i]);
		csum += a[i];
		if (i-c >= 0) {
			if (i-c >= 1) {
				curin.erase(curin.find(a[i-c]));
				csum -= a[i-c];
			}
			dp[i] = min(dp[i], dp[i-c] + csum - *curin.begin());
		}

	}
	cout << dp[n] << endl;
	cin >> n;
}