#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;


int n;
vector<int> a;
const int p = 5;
vector<vector<bool>> dp;
vector<int> res;


void rec(int c) {
	dp[c].resize(p, false);
	if (c == 0) {
		for (int i = 0; i < p; ++i) {
			dp[0][i] = true;
		}
		return;
	}
	rec(c - 1);
	if (a[c - 1] < a[c]) {
		for (int i = 0; i < p; ++i) {
			for (int j = 0; j < i; ++j) {
				if (dp[c - 1][j]) {
					dp[c][i] = true;
				}
			}
		}
	}
	else if (a[c - 1] > a[c]) {
		for (int i = 0; i < p; ++i) {
			for (int j = i + 1; j < p; ++j) {
				if (dp[c - 1][j]) {
					dp[c][i] = true;
				}
			}
		}
	}
	else {
		for (int i = 0; i < p; ++i) {
			for (int j = 0; j < p; ++j) {
				if (dp[c - 1][j] && j != i) {
					dp[c][i] = true;
				}
			}
		}
	}
}


void get_res(int c, int i) {
	res[c] = i;
	if (c == 0) {
		return;
	}
	if (a[c - 1] < a[c]) {
		for (int j = 0; j < i; ++j) {
			if (dp[c - 1][j]) {
				get_res(c - 1, j);
				return;
			}
		}
	}
	else if (a[c - 1] > a[c]) {
		for (int j = i + 1; j < p; ++j) {
			if (dp[c - 1][j]) {
				get_res(c - 1, j);
				return;
			}
		}
	}
	else {
		for (int j = 0; j < p; ++j) {
			if (dp[c - 1][j] && j != i) {
				get_res(c - 1, j);
				return;
			}
		}
	}
}


int main() {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	dp.resize(n);
	rec(n - 1);
	res.resize(n);
	for (int i = 0; i < p; ++i) {
		if (dp[n - 1][i]) {
			get_res(n - 1, i);
			for (auto i: res) {
				cout << i + 1 << " ";
			}
			cout << "\n";
			return 0;
		}
	}
	cout << -1 << "\n";
	return 0;
}