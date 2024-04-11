#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;

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

int n, k;
int to[32][2], row[50][50], col[50][50];

void solve() {
    read(n); read(k);
    to[1][0] = 1;
    to[3][0] = 4;
    to[7][0] = 16;
    to[15][0] = 64;
    to[31][0] = 256;
    int m1 = 1 + 4 + 16 + 64 + 256;
    to[1][1] = 2;
    to[3][1] = 8;
    to[7][1] = 32;
    to[15][1] = 128;
    to[31][1] = 512;
    int m2 = 2 + 8 + 32 + 128 + 512;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < n; ++j) {
            printf("%d ", row[i][j] = to[j ^ (j - 1)][0]);
        }
        printf("\n");
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%d ", col[i][j] = to[i ^ (i - 1)][1]);
        }
        printf("\n");
    }
    fflush(stdout);
    int x = 1, y = 1;
    while (k--) {
        int xr; read(xr);
        int r = (xr & m1), c = (xr & m2);
        int tmp = 0, flag = 0;
        for (int i = y - 1; i >= 1; --i) {
            tmp ^= row[x][i];
            if (tmp == r) {
                y = i;
                flag = 1;
                break;
            }
        }
        if (!flag) {
            tmp = 0;
            for (int i = y + 1; i <= n; ++i) {
                tmp ^= row[x][i - 1];
                if (tmp == r) {
                    y = i;
                    break;
                }
            }
        }
        tmp = 0; flag = 0;
        for (int i = x - 1; i >= 1; --i) {
            tmp ^= col[i][y];
            if (tmp == c) {
                x = i;
                flag = 1;
                break;
            }
        }
        if (!flag) {
            tmp = 0;
            for (int i = x + 1; i <= n; ++i) {
                tmp ^= col[i - 1][y];
                if (tmp == c) {
                    x = i;
                    break;
                }
            }
        }
        printf("%d %d\n", x, y);
        fflush(stdout);
    }
}

int main() {
    solve();
    return 0;
}