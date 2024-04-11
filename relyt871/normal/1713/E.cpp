#include<bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int N = 1005;

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

int n, a[N][N], ufs[N], val[N];

int getf(int x) {
    if (ufs[x] == x) return x;
    int ret = getf(ufs[x]);
    val[x] ^= val[ufs[x]];
    return ufs[x] = ret;
}

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            read(a[i][j]);
        }
        ufs[i] = i;
        val[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (a[i][j] == a[j][i]) continue;
            int u = getf(i), v = getf(j);
            if (a[i][j] < a[j][i]) {
                if (u == v && val[i] != val[j]) {
                    swap(a[i][j], a[j][i]);
                } else if (u != v) {
                    ufs[u] = v;
                    val[u] = val[i] ^ val[j];
                }
            } else {
                if (u == v && val[i] == val[j]) {
                    //do nothing
                } else {
                    swap(a[i][j], a[j][i]);
                    if (u != v) {
                        ufs[u] = v;
                        val[u] = 1 ^ val[i] ^ val[j];
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}