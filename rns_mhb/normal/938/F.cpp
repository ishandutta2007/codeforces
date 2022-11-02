#include <bits/stdc++.h>
using namespace std;
#define pc putchar
#define bitctz __builtin_ctz
#define bitclz __builtin_clz
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)

#define N 5005

char s[N];

int n;
bool dp[N][N];

int main() {
    scanf("%s", s + 1);
    n = strlen(s+1);
    int m = (1 << 31 - bitclz(n)) - 1;
    int left = n - m, p;
    f1(i, 0, n - left) dp[i][i] = 1;
    char ch = 'z' + 1;
    f1(i, 1, n) if (dp[i-1][i-1] && s[i] < ch) {
		ch = s[i];
        p = i;
    }
    f1(i, 1, left) {
        dp[p][p-i] = 1;
        int up = n - left + i, k;
        f1(j, p+1, up) {
            k = j - i;
            if (dp[j-1][k] && ch == s[j]) dp[j][k] = 1;
            for (int p = k; p && !dp[j][k]; p -= p & -p) {
                int u = 1 << bitctz(p);
                if (dp[j-u][k-u]) {
                    dp[j][k] = 1;
                    break;
                }
            }
        }
        ch = 'z' + 1;
        f1(j, i+1, n) if (dp[j-1][j-i-1] && s[j] < ch) {
            ch = s[j];
            p = j;
        }
    }
    f1(i, 1, left) {
        f1(j, i, n) if (dp[j][j-i]) {
			pc(s[j]);
			break;
        }
    }
	return 0;
}