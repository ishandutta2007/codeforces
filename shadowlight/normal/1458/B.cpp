#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 107;
const int NN = N * N;

int dp[N][4 * NN], dpn[N][4 * NN];

const int INF = 1e9 + 7;

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector <int> a(n), b(n);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 4 * NN; ++j) {
			dp[i][j] = -INF;
		}
	}
	dp[0][2 * NN] = 0;

	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		a[i] *= 2, b[i] *= 2;
	}

	for (int i = 0; i < n; ++i) {
		for (int k = 0; k < N; ++k) {
			for (int t = 0; t < 4 * NN; ++t) {
				dpn[k][t] = -INF;
			}
		}
		for (int cnt = 0; cnt < n; ++cnt) {
			for (int j = -2 * NN; j < 2 * NN; ++j) {
				if (dp[cnt][j + 2 * NN] == -INF) continue;
				/*if (cnt == 2) {
					cout << "ITER: " << i << " " << j << " " << dp[cnt][j + 2 * NN] << "\n";
				}*/
				int now1 = dp[cnt][j + 2 * NN] + b[i];
				int jj = j + (a[i] - b[i]);
				if (j < 0) {
					now1 += min(abs(j), a[i] - b[i]);
				}
				dpn[cnt + 1][jj + 2 * NN] = max(dpn[cnt + 1][jj + 2 * NN], now1);
				
				int now2 = dp[cnt][j + 2 * NN];
				int jj2 = j - b[i] / 2;
				if (j > 0) {
					now2 += min(abs(j), b[i] / 2);
				}

				dpn[cnt][jj2 + 2 * NN] = max(dpn[cnt][jj2 + 2 * NN], now2);
			}
		}
		swap(dp, dpn);
	}

	cout.precision(20);
	for (int i = 1; i <= n; ++i) {
		int res = -INF;
		for (int j = -2 * NN; j < 2 * NN; ++j) {
			res = max(res, dp[i][j + 2 * NN]);
		}
		cout << fixed << (db) res / 2. << " ";
	}
}