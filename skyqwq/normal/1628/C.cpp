// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e3 + 5;

int c[N][N], n, a[N][N];
 
void inline work(int x, int o) {
    if (x > n / 2) return;
    for (int j = x; j <= n - x + 1; j++)
        c[x][j] = o, c[n - x + 1][j] = o ^ 1;
    for (int i = x; i <= n - x + 1; i ++)
        c[i][x] = c[i][n - x + 1] = ((i - x) & 1) ^ o;
    for (int j = x + 1; j <= n - x; j++)
        c[x + 1][j] = c[n - x][j] = c[j][x + 1] = c[j][n - x] = o ^ 1;

    work(x + 2, o ^ 1);
}

int main() {
    int T; read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) c[i][j] = 0;
        work(1, 0);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int x; read(x);
                if (c[i][j]) ans ^= x;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}