#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 2e5 + 7;
int dp[N][2][2][2][2];

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector <bool> go(n);
	for (int i = 0; i < n; ++i) {
		go[i] = (s[i] == 'R');
	}
	for (int i = 0; i < n; ++i) {
		for (int a = 0; a < 2; ++a) {
			for (int b = 0; b < 2; ++b) {
				for (int c = 0; c < 2; ++c) {
					for (int d = 0; d < 2; ++d) {
						dp[i][a][b][c][d] = N;
					}
				}
			}
		}
	}
	for (int a = 0; a < 2; ++a) {
		for (int b = 0; b < 2; ++b) {
			dp[1][a][b][a][b] = (a != go[0]) + (b != go[1]);
		}
	}
	for (int i = 2; i < n; ++i) {
		for (int a = 0; a < 2; ++a) {
			for (int b = 0; b < 2; ++b) {
				for (int c = 0; c < 2; ++c) {
					for (int e = 0; e < 2; ++e) {
						for (int d = 0; d < 2; ++d) {
							int cf = (go[i] != d);
							if (a == b && b == d) continue;
							dp[i][b][d][c][e] = min(dp[i][b][d][c][e], dp[i - 1][a][b][c][e] + cf);
						}
					}
				}
			}
		}
	}
	int res = N;
	for (int a = 0; a < 2; ++a) {
		for (int b = 0; b < 2; ++b) {
			for (int c = 0; c < 2; ++c) {
				for (int d = 0; d < 2; ++d) {
					if (a == b && b == c) continue;
					if (b == c && c == d) continue;
					res = min(res, dp[n - 1][a][b][c][d]);
				}
			}
		}
	}
	cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}

}