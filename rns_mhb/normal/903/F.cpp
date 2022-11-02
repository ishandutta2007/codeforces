#include <bits/stdc++.h>
using namespace std;
#define bitclz __builtin_clz
#define f0(i, a, b) for (int i = a; i < b; i ++)
template <class T> void chkmin(T &a, T b) {if (a > b) a = b;}

const int inf = 0x3f3f3f3f;

#define N 1005
const int M = 1 << 12;

int n, dp[N][M], a[5];
char s[5][N];

int main() {
    scanf("%d", &n);
    f0(i, 1, 5) scanf("%d", &a[i]);
    f0(i, 0, 4) scanf("%s", s[i]);
    int up = 1 << 12;
    int m = n - 2, mid = 1 << 8;
    dp[0][0] = 0;
    f0(i, 1, up) {
    	dp[0][i] = a[4];
        int k = 31 - bitclz(i);
        int r = k % 4, c = k / 4;
        if (s[r][c] == '.') dp[0][i] = dp[0][i-(1<<k)];
        else {
            chkmin(dp[0][i], dp[0][i-(1<<k)] + a[1]);
			chkmin(dp[0][i], dp[0][i&2184] + a[3]);
			chkmin(dp[0][i], dp[0][i&273] + a[3]);
            if (c < 2) {
                chkmin(dp[0][i], dp[0][i&51] + a[2]);
                chkmin(dp[0][i], dp[0][i&102] + a[2]);
                chkmin(dp[0][i], dp[0][i&204] + a[2]);
            }
            else {
                chkmin(dp[0][i], dp[0][i&3279] + a[2]);
                chkmin(dp[0][i], dp[0][i&2463] + a[2]);
                chkmin(dp[0][i], dp[0][i&831] + a[2]);
            }
        }
    }
	f0(i, 1, m) {
        f0(j, 0, mid) dp[i][j] = dp[i-1][(j<<4)+15];
		f0(j, mid, up) {
            dp[i][j] = dp[i-1][0] + a[4];
            int k = 31 - bitclz(j);
            int r = k % 4;
            bool flag = (j == 511);
            if (s[r][i+2] == '.') chkmin(dp[i][j], dp[i][j-(1<<k)]);
            else {
                chkmin(dp[i][j], dp[i][j-(1<<k)] + a[1]);
                chkmin(dp[i][j], dp[i][j&3279] + a[2]);
                chkmin(dp[i][j], dp[i][j&2463] + a[2]);
                chkmin(dp[i][j], dp[i][j&831] + a[2]);
                chkmin(dp[i][j], dp[i][j&2184] + a[3]);
                chkmin(dp[i][j], dp[i][j&273] + a[3]);
            }
		}
	}
    printf("%d\n", dp[m-1][up-1]);
	return 0;
}