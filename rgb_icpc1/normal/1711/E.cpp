#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long LL;

const int MX = 200005;
const int MOD = 998244353;
const int r3 = 332748118;

inline int add(int x, int y) {return (x + y) % MOD;}
inline int mul(int x, int y) {return 1LL * x * y % MOD;}
inline void Add(int &x, int y) {x = add(x, y);}
inline void Mul(int &x, int y) {x = mul(x, y);}

int Tc, N;
int dp[8][8][MX];
int a[] = {0, 1, 2, 4, 4, 2, 1, 0};
char str[MX];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int i, j, k;
	cin >> str;
	N = strlen(str);
	for (i = 0; i < 8; i++) dp[i][0][N] = 1;
	for (i = N - 1; i >= 0; i--) {
		if (str[i] == '0') {
//			for (k = 0; k < 8; k++)
//			for (int u = 0; u < 8; u++) {
//				if (i == 1) cerr << k << ' ' << u << ' ' << dp[k][u][i + 1] << '\n';
//			}
			for (k = 0; k < 8; k++) dp[0][k][i] = dp[0][k][i + 1];
			for (k = 0; k < 8; k++) dp[1][k][i] = dp[1][k][i + 1];
			for (k = 0; k < 8; k++) Add(dp[1][k | 1][i], dp[1][k][i + 1]);
			for (k = 0; k < 8; k++) dp[2][k][i] = dp[2][k][i + 1];
			for (k = 0; k < 8; k++) Add(dp[2][k | 2][i], dp[2][k][i + 1]);
			for (k = 0; k < 8; k++) dp[4][k][i] = dp[4][k][i + 1];
			for (k = 0; k < 8; k++) Add(dp[4][k | 4][i], dp[4][k][i + 1]);
			for (k = 0; k < 8; k++) dp[3][k][i] = dp[3][k][i + 1];
			for (k = 0; k < 8; k++) Add(dp[3][k | 1][i], dp[3][k][i + 1]);
			for (k = 0; k < 8; k++) Add(dp[3][k | 2][i], dp[3][k][i + 1]);
			for (k = 0; k < 8; k++) Add(dp[3][k | 4][i], dp[3][k][i + 1]);
			for (k = 0; k < 8; k++) dp[5][k][i] = dp[5][k][i + 1];
			for (k = 0; k < 8; k++) Add(dp[5][k | 1][i], dp[5][k][i + 1]);
			for (k = 0; k < 8; k++) Add(dp[5][k | 2][i], dp[5][k][i + 1]);
			for (k = 0; k < 8; k++) Add(dp[5][k | 4][i], dp[5][k][i + 1]);
			for (k = 0; k < 8; k++) dp[6][k][i] = dp[6][k][i + 1];
			for (k = 0; k < 8; k++) Add(dp[6][k | 1][i], dp[6][k][i + 1]);
			for (k = 0; k < 8; k++) Add(dp[6][k | 2][i], dp[6][k][i + 1]);
			for (k = 0; k < 8; k++) Add(dp[6][k | 4][i], dp[6][k][i + 1]);
			for (k = 0; k < 8; k++) dp[7][k][i] = add(dp[7][k][i + 1], dp[7][k][i + 1]);
			for (k = 0; k < 8; k++) Add(dp[7][k | 1][i], add(dp[7][k][i + 1], dp[7][k][i + 1]));
			for (k = 0; k < 8; k++) Add(dp[7][k | 2][i], add(dp[7][k][i + 1], dp[7][k][i + 1]));
			for (k = 0; k < 8; k++) Add(dp[7][k | 4][i], add(dp[7][k][i + 1], dp[7][k][i + 1]));
//			for (int u = 0; u < 8; u++) {
//				if (i == 1) cerr << u << ' ' << dp[0][u][i] << '\n';
//			}
		} else {
			for (k = 0; k < 8; k++) {
				for (int u = 0; u < 8; u++) {
					for (int v = 0; v < 8; v++) {
//						cerr << k << ' ' << int(k | a[u]) << ' ' << dp[v][k | a[u]][i] << '\n';
						Add(dp[v][k | a[u]][i], dp[u | v][k][i + 1]);
//						if (i == 1) cerr << int(k|a[u]) << ' ' << dp[0][k | a[u]][i] << '\n';
					}
				}
			}
//			for (k = 0; k < 8; k++) dp[0][k][i] = dp[0][k][i + 1];
//			for (k = 0; k < 8; k++) Add(dp[0][k | 1][i], dp[1][k][i + 1]);
//			for (k = 0; k < 8; k++) Add(dp[0][k | 2][i], dp[2][k][i + 1]);
//			for (k = 0; k < 8; k++) Add(dp[0][k | 4][i], dp[4][k][i + 1]);
//			for (k = 0; k < 8; k++) Add(dp[0][k | 4][i], dp[3][k][i + 1]);
//			for (k = 0; k < 8; k++) Add(dp[0][k | 2][i], dp[5][k][i + 1]);
//			for (k = 0; k < 8; k++) Add(dp[0][k | 1][i], dp[6][k][i + 1]);
//			for (k = 0; k < 8; k++) Add(dp[0][k][i], dp[7][k][i + 1]);
//			for (k = 0; k < 8; k++) dp[1][k][i] = dp[1][k][i + 1];
//			for (k = 0; k < 8; k++) Add(dp[1][k | 1][i], dp[1][k][i + 1]);
//			for (k = 0; k < 8; k++) Add(dp[1][k | 2][i], dp[3][k][i + 1]);
//			for (k = 0; k < 8; k++) Add(dp[1][k | 4][i], dp[5][k][i + 1]);
//			for (k = 0; k < 8; k++) Add(dp[1][k | 4][i], dp[3][k][i + 1]);
//			for (k = 0; k < 8; k++) Add(dp[1][k | 2][i], dp[5][k][i + 1]);
//			for (k = 0; k < 8; k++) Add(dp[1][k | 1][i], dp[7][k][i + 1]);
//			for (k = 0; k < 8; k++) Add(dp[1][k][i], dp[7][k][i + 1]);
		}
//		for (int u = 0; u < 8; u++) {
//			int s = 0;
//			for (k = 0; k < 8; k++) Add(s, dp[u][k][i]);
//			cerr << u << ' ' << s << '\n';
//		}
	}
	cout << dp[0][7][0] << '\n';

    return 0;

}