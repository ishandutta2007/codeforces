// Skyqwq
#include <bits/stdc++.h>

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

const int N = 105;

int a[3][N], n;
 
int main() {
    int T; read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= 2; i++)
            for (int j = 1; j <= n; j++) scanf("%1d", &a[i][j]);
        bool o = 1;
        for (int i = 1; i <= n; i++) {
            if (a[1][i] && a[2][i]) o = 0;
        }
        puts(o ? "YES" : "NO");
    }
    return 0;
}