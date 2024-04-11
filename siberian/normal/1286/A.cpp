#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
#define int ll
const int MAXN = 110;
int dp[MAXN][MAXN][MAXN][2];
int n;
int a[MAXN];
void read() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 0) a[i] = -1;
		else a[i] %= 2;
	}
}


const int INF = 1e9;
int ans;

void run() {
	int cnt1 = (n + 1) / 2, cnt0 = n / 2;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0)
			cnt0--;
		else if (a[i] == 1)
			cnt1--;
	}

	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			for (int k = 0; k < MAXN; k++)
				for (int l = 0; l < 2; l++)
					dp[i][j][k][l] = INF;

	/*cout << "a = " << endl;
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;

	cout << cnt0 << " " << cnt1 << endl;*/
				
	if (a[1] == -1) {
		if (cnt0)
			dp[1][1][0][0] = 0;
		if (cnt1)
			dp[1][0][1][1] = 0;
	}
	else {
		dp[1][0][0][a[1]] = 0;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= cnt0; j++) {
			for (int k = 0; k <= cnt1; k++) {
				for (int a0 = 0; a0 < 2; a0++) {
					for (int a1 = 0; a1 < 2; a1++) {
						if (a[i] == -1) {
							if ((a1 == 0 && j > 0) || (a1 == 1 && k > 0))
							chkmin(dp[i][j][k][a1], dp[i - 1][j - (a1 == 0)][k - (a1 == 1)][a0] + (a0 != a1));
						}
						else if (a1 == a[i]) {
							chkmin(dp[i][j][k][a1], dp[i - 1][j][k][a0] + (a0 != a1));
						}
					}
				}
			}
		}
	}

	ans = min(dp[n][cnt0][cnt1][0], dp[n][cnt0][cnt1][1]);
}

void write() {
	cout << ans << endl;
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