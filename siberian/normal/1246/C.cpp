#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MOD = 1e9 + 7;
const int MAXN = 2e3 + 10;
int n, m;
char table[MAXN][MAXN];

void read() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> table[i][j];
		}
	}
}

int Right[MAXN][MAXN], Down[MAXN][MAXN];

void build() {
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {
			Right[i][j] = Right[i][j + 1] + (table[i][j] == 'R');
		}
	}
	for (int j = 1; j <= m; j++) {
		for (int i = n; i >= 1; i--) {
			Down[i][j] = Down[i + 1][j] + (table[i][j] == 'R');
		}
	}
}

int add(int a, int b) {
	a += b;
	if (a >= MOD)
		a -= MOD;
	return a;
}

int sub(int a, int b) {
	a -= b;
	if (a < 0)
		a += MOD;
	return a;
}

int dp[MAXN][MAXN][3];
int plus_r[MAXN][MAXN][3], plus_d[MAXN][MAXN][3];

void calc() {
	dp[1][1][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < 3; k++) {
				plus_r[i][j][k] = add(plus_r[i][j][k], plus_r[i][j - 1][k]);
				plus_d[i][j][k] = add(plus_d[i][j][k], plus_d[i - 1][j][k]);
				dp[i][j][k] = add(dp[i][j][k], add(plus_r[i][j][k], plus_d[i][j][k]));
			}

			if (table[i + 1][j] == '.') {
				dp[i + 1][j][0] = add(dp[i + 1][j][0], add(dp[i][j][0], dp[i][j][1]));
			}
			else {
				//dp[i + 1][j][2] = add(dp[i + 1][j][2], add(dp[i][j][0], dp[i][j][1]));
				plus_d[i][j][2] = add(plus_d[i][j][2], add(dp[i][j][0], dp[i][j][1]));
				int k = n - Down[i + 1][j] + 1;
				plus_d[k][j][2] = sub(plus_d[k][j][2], add(dp[i][j][0], dp[i][j][1]));
				
				//for (int k = i + 1; k <= n - Down[i + 1][j]; k++) {
				//	dp[k][j][2] = add(dp[k][j][2], add(dp[i][j][0], dp[i][j][1]));
				//}
			}
			if (table[i][j + 1] == '.') {
				dp[i][j + 1][0] = add(dp[i][j + 1][0], add(dp[i][j][0], dp[i][j][2]));
			}
			else {
				//dp[i][j + 1][1] = add(dp[i][j + 1][1], add(dp[i][j][0], dp[i][j][2]));
				plus_r[i][j][1] = add(plus_r[i][j][1], add(dp[i][j][0], dp[i][j][2]));
				int k = m - Right[i][j + 1] + 1;
				plus_r[i][k][1] = sub(plus_r[i][k][1], add(dp[i][j][0], dp[i][j][2]));
		
				//for (int k = j + 1; k <= m - Right[i][j + 1]; k++) {
				//	dp[i][k][1] = add(dp[i][k][1], add(dp[i][j][0], dp[i][j][2]));
				//}
			}
		}
	}
}

void run() {
	build();
	calc();
	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << dp[i][j][0] + dp[i][j][1] + dp[i][j][2] << " ";
		}
		cout << endl;
	}*/
}

void write() {
	cout << (dp[n][m][0] + dp[n][m][1] + dp[n][m][2]) % MOD << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}