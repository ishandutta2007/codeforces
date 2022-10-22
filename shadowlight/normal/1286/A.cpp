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

int dp[N][N][N][2];

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				dp[i][j][k][0] = N;
				dp[i][j][k][1] = N;
			}
		}
	}
	int n;
	cin >> n;
	vector <int> a(n);
	vector <bool> was(n, false);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		if (a[i] != -1) {
			was[a[i]] = true;
		}
	}
	int odd = 0, even = 0, res = 0;
	for (int i = 0; i < n; i++) {
		if (!was[i]) {
			odd += i % 2;
			even += (i + 1) % 2;
		}
		if (i != n - 1 && a[i] != -1 && a[i + 1] != -1) {
			res += (a[i] % 2) != (a[i + 1] % 2);
		}
	}
	dp[0][0][0][0] = 0;
	dp[0][0][0][1] = 0;
	//cout << odd << " " << even << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= even; j++) {
			for (int k = 0; k <= odd; k++) {
				for (int l = 0; l < 2; l++) {
					if (dp[i][j][k][l] == N) continue;
					//cout << dp[i][j][k][l] << " " << i << " " << j << " " << k << " " << l << "\n";
					if (a[i] != -1) {
						int x = a[i] % 2;
						dp[i + 1][j][k][a[i] % 2] = min(dp[i][j][k][l] + (bool) (x != l), dp[i + 1][j][k][a[i] % 2]);
						//cout << dp[i + 1][j][k][a[i] % 2] << "\n";
					} else {
						dp[i + 1][j + 1][k][0] = min(dp[i + 1][j + 1][k][0], dp[i][j][k][l] + (l));
						dp[i + 1][j][k + 1][1] = min(dp[i + 1][j][k + 1][1], dp[i][j][k][l] + (!l));
					}
				}
			}
		}
	}
	cout << min(dp[n][even][odd][0], dp[n][even][odd][1]);
}