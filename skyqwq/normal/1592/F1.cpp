// Skyqwq
#include <iostream>
#include <cstdio>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 505;

int n, m, a[N][N], s[N][N], ans, b[N][N];

char g[N][N];
 
int main() {
    read(n), read(m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", g[i] + 1);
        for (int j = 1; j <= m; j++) a[i][j] = g[i][j] == 'B';
    }
    for (int i = n; i; i--) {
        for (int j = m; j; j--) {
            s[i][j] = s[i + 1][j] ^ s[i][j + 1] ^ s[i + 1][j + 1];
            if (s[i][j] != a[i][j]) s[i][j] ^= 1, ans++, b[i][j] = 1;
        }
    }
    int o = 0;
    for (int x = 1; x < n; x++) {
        for (int y = 1; y < m; y++) {
            if (b[x][y] && b[x][m] && b[n][y] && b[n][m]) o = 1;
        }
    }
    ans -= o;
    printf("%d\n", ans);
	return 0;
}