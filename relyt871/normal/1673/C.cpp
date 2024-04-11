#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 40005;
const int MOD = 1e9 + 7;

inline void Inc(int &x, int y) {
    x += y; if (x >= MOD) x -= MOD;
}

template <typename T> inline void read(T &WOW) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	WOW = flag * x;
}

int pal[MAXN], tot;
int dp[MAXN][500];

bool check(int x) {
    static int s[10], t;
    t = 0;
    while (x) {
        s[++t] = x % 10;
        x /= 10;
    }
    for (int i = 1; i <= t; ++i) {
        if (s[i] != s[t - i + 1]) {
            return 0;
        }
    }
    return 1;
}

void prework() {
    int n = 40000;
    for (int i = 1; i <= n; ++i) {
        if (check(i)) {
            pal[++tot] = i;
        }
    }
//printf("%d\n", tot); =498
    for (int i = 0; i <= tot; ++i) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= tot; ++j) {
            dp[i][j] = dp[i][j - 1];
            if (pal[j] <= i) {
                Inc(dp[i][j], dp[i - pal[j]][j]);
            }
        }
    }
}

int main() {
    prework();
    int T; read(T);
    while (T--) {
        int n; read(n);
        printf("%d\n", dp[n][tot]);
    }
    return 0;
}