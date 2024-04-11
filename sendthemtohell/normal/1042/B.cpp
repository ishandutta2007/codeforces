#include "bits/stdc++.h"

#define all(v) (v).begin(),(v).end()

using namespace std;

int dp[8][2057];

int main() {
	int n;
	cin >> n;
	vector<pair<int,int>> v(n);
	for(int i = 0; i < n; ++i) {
		string c;
		v[i].second = 0;
		cin >> v[i].first >> c;
		for(int j = 0; j < c.size(); ++j) {
			v[i].second |= (1 << (c[j] - 'A'));
		}
	}
	for(int i = 0; i < 2000; ++i) {
		for(int msk = 1; msk < 8; ++msk) {
			dp[msk][i] = 22222222;
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int msk = 0; msk < 8; ++msk) {
			dp[msk][i + 1] = min(dp[msk][i + 1], dp[msk][i]);
			dp[msk|v[i].second][i + 1] = min(dp[msk|v[i].second][i + 1], dp[msk][i] + v[i].first);
		}
	}
	if(dp[7][n] < 2222222) {
		cout << dp[7][n] << endl;
	}
	else {
		cout << -1 << endl;
	}
}