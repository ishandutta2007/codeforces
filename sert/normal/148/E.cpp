#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int M = (int)1e4 + 5;

int max_cost[N][N];
int dp[N][M];
int num[N];
int a[N];

inline void mxe(int &a ,int b) {
	if (b > a)
		a = b;
}

int main() {
	int n, m, sum = 0, sum_all;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
		sum_all = 0;
		for (int j = 0; j < num[i]; j++) {
			cin >> a[j];
			sum_all += a[j];
		}	
		max_cost[i][num[i]] = sum_all;
		for (int st = 0; st < num[i]; st++) {
		     sum = 0;
		     for (int fn = st; fn < num[i]; fn++) {
		     	 sum += a[fn];
		     	 mxe(max_cost[i][num[i] - (fn - st + 1)], sum_all - sum);	
		     }
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int k = 0; k <= num[i] && j + k <= m; k++) {
				mxe(dp[i + 1][j + k], dp[i][j] + max_cost[i][k]);
			}
		}
	}

	cout << dp[n][m];

	return 0;
}