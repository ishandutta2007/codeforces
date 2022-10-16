// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 505, P = 998244353;

int f[N][N], pw[N][N], n, m, C[N][N];

int inline power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (LL)res * a % P;
        a = (LL)a * a % P;
        b >>= 1;
    }
    return res;
}
 
void inline add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}


int main() {
    read(n), read(m);

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) pw[i][j] = power(i, j);
    for (int i = 0; i <= m; i++) f[0][i] = 1;
    pw[0][0] = 1;
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j <= i - 1) f[i][j] = pw[j][i];
            else {
                for (int k = 0; k <= i; k++) {
                    add(f[i][j], 1ll * f[i - k][j - i + 1] * C[i][k] % P * pw[min(i - 1, j)][k] % P);
                }
            }
        }
    }
    printf("%d\n", f[n][m]);
    return 0;
}