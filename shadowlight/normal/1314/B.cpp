#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int INF = 1e9 + 7;
const int LOGN = 18;
const int N = (1 << LOGN);

int dp[LOGN][4][N];

void upd(int &x, int val) {
	x = max(x, val);
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	if (!k) {
		cout << "0\n";
		return 0;
	}

	for (int i = 0; i < LOGN; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < N; k++) {
				dp[i][j][k] = -INF;
			}
		}
	}

	int m = (1 << n);

	vector <bool> exist(m, false);

	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		x--;
		exist[x] = true;
	}

	for (int i = 0; i < m / 2; i++) {
		if (exist[2 * i] && exist[2 * i + 1]) {
			dp[0][3][i] = 1;
		} else if (exist[2 * i] || exist[2 * i + 1]) {
			dp[0][2][i] = 1;
		} else {
			dp[0][0][i] = 0;
		}
	}

	for (int lvl = 1; lvl < n; lvl++) {
		int sz = m / (1 << (lvl + 1));
		for (int i = 0; i < sz; i++) {
			for (int fp = 0; fp < 4; fp++) {
				for (int sp = 0; sp < 4; sp++) {
					int sum = dp[lvl - 1][fp][2 * i] + dp[lvl - 1][sp][2 * i + 1];
					if (dp[lvl - 1][fp][2 * i] == -INF || dp[lvl - 1][sp][2 * i + 1] == -INF) continue;
					//cout << lvl << " " << i << " " << fp << " " << sp << " " << sum << "\n";
					if ((fp & 2) || (sp & 2)) {
						upd(dp[lvl][2][i], sum + 1);
						upd(dp[lvl][1][i], sum + 2);
					}
					if (fp == 3 || sp == 3) {
						upd(dp[lvl][3][i], sum + 3);
					}
					if (max(fp, sp) == 2 && min(fp, sp) >= 1) {
						upd(dp[lvl][3][i], sum + 3);
					}
					if (fp == 1 || sp == 1) {
						upd(dp[lvl][1][i], sum + 2);
					}
					upd(dp[lvl][0][i], 0);
				}
			}
		}
	}

	int res = 0;

	for (int i = 0; i < 4; i++) {
		upd(res, dp[n - 1][i][0]);
	}
	cout << res + 1 << "\n";
}