#include <iostream>
#include <vector>
using namespace std;

const int maxN = 24;
const int inf = 1000000000;
int n, xs, ys;
int a[maxN][maxN];
int dp[1 << maxN];
int x[maxN], y[maxN];

int dist(int x1, int y1, int x2, int y2) {
	int dx = (x1 - x2);
	int dy = (y1 - y2);
	return dx * dx + dy * dy;
}

int main() {
	cin >> xs >> ys;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i][j] = dist(xs, ys, x[i], y[i]) + dist(x[i], y[i], x[j], y[j]) + dist(x[j], y[j], xs, ys);
		}
	}
	
	for (int i = 0; i < (1 << n); ++i) {
		dp[i] = inf;
	}
	dp[0] = 0;
	for (int i = 1; i < (1 << n); ++i) {
		int j = __builtin_ctz(i);
		dp[i] = min(dp[i], dp[i ^ (1 << j)] + a[j][j]);
		
		for (int k = j + 1; k < n; ++k) {
			if (i & (1 << k)) {
				dp[i] = min(dp[i], dp[i ^ (1 << j) ^ (1 << k)] + a[k][j]);
			}
		}
	}
	int res = dp[(1 << n) - 1];
	vector < int > order;
	order.push_back(0);
	int mask = (1 << n) - 1;
	while (mask) {
		int j = __builtin_ctz(mask);
		if (dp[mask] == dp[mask ^ (1 << j)] + a[j][j]) {
			order.push_back(j + 1);
			order.push_back(0);
			mask ^= (1 << j);
			continue;
		}
		for (int k = j + 1; k < n; ++k) {
			if (mask & (1 << k)) {
				if (dp[mask] == dp[mask ^ (1 << j) ^ (1 << k)] + a[j][k]) {
					order.push_back(j + 1);
					order.push_back(k + 1);
					order.push_back(0);
					mask ^= (1 << j);
					mask ^= (1 << k);
					break;
				}
			}
		}
	}
	cout << res << endl;
	for (int i = 0; i < order.size(); ++i) {
		cout << order[i] << " ";
	}
	return 0;
}