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

const int N = 2005, P = 1e9 + 7;

int n, m, k;
 
int f[N][N], inv2 = (P + 1) / 2;

int main() {
    int T; read(T);
    while (T--) {
        read(n), read(m), read(k);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= min(i, m); j++) {
                if (j == 0) f[i][j] = (f[i - 1][j]);
                else if (j == i) f[i][j] = (f[i - 1][j - 1] + k) % P;
                else {
                    LL b = f[i - 1][j - 1], a = f[i - 1][j];
                    f[i][j] = 1ll * (a + b) * inv2 % P;
                }
            }
        }
        cout << (f[n][m]) << endl;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++) f[i][j] = 0;
    }
    return 0;
}