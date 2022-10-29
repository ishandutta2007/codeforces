#include <bits/stdc++.h>

using namespace std;

const int N = 122;
const int K = 5;
const int INF = 1e9 + 7;

int a[N][K];
int n;

double gain(int pts, int x) {
	if (x == -1) return 0;
	return pts * (1 - 1. * x / 250);
}

bool solve(int t) {
	int tot = n + t;
	int cnt[K] = {0};
	for (int i = 0; i < K; i++) {
		bool flag = false;
		if (a[0][i] != -1 && a[1][i] != -1 && a[0][i] > a[1][i]) flag = true;
		if (flag) {
			cnt[i] += t;
			// cout << i << " ";
		}
	}
	// cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < K; j++) {
			if (a[i][j] != -1) {
				cnt[j]++;
			}
		}
	}
	double diff = 0;
	for (int i = 0; i < K; i++) {
		double ratio = 1. * cnt[i] / tot;
		// cout << ratio << endl;
		if (ratio > 1. / 2) {
			diff += gain(500, a[0][i]) - gain(500, a[1][i]);
		} else if (ratio > 1. / 4) {
			diff += gain(1000, a[0][i]) - gain(1000, a[1][i]);
		} else if (ratio > 1. / 8) {
			diff += gain(1500, a[0][i]) - gain(1500, a[1][i]);
		} else if (ratio > 1. / 16) {
			diff += gain(2000, a[0][i]) - gain(2000, a[1][i]);
		} else if (ratio > 1. / 32) {
			diff += gain(2500, a[0][i]) - gain(2500, a[1][i]);
		} else {
			diff += gain(3000, a[0][i]) - gain(3000, a[1][i]);
		}
	}
	return diff > 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < K; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	int ans = INF + 1;
	for (int i = 0; i <= 32 * n + 100; i++) {
		if (solve(i)) {
			ans = i;
			break;
		}
	}
	if (ans > INF) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
}