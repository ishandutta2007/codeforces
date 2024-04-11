#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 505;
const int NN = N * N;

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

template <typename T> inline void cmin(T &x, T y) {
    if (x > y) x = y;
}
template <typename T> inline void cmax(T &x, T y) {
    if (x < y) x = y;
}

int n, nn, k, a[N][N];
int vis[NN], xl[NN], xr[NN], yl[NN], yr[NN], sum[N][N];

void solve() {
    read(n); read(k);
    nn = n * n;
    for (int i = 1; i <= nn; ++i) {
        xl[i] = yl[i] = n + 1;
        xr[i] = yr[i] = -1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int u; read(u);
            a[i][j] = u;
            vis[u] = 1;
            cmin(xl[u], i); cmax(xr[u], i);
            cmin(yl[u], j); cmax(yr[u], j);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= nn; ++i) {
        cnt += vis[i];
    }
    if (cnt <= k) {
        printf("%d\n", k - cnt);
        return;
    }
    if (k == 1) {
        printf("1\n");
        return;
    }
    for (int l = 1; l < n; ++l) {
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= nn; ++i) {
            if (!vis[i]) continue;
            int px = max(0, xr[i] - l), py = max(0, yr[i] - l);
            if (px < xl[i] && py < yl[i]) {
                ++sum[xl[i]][yl[i]];
                --sum[px][yl[i]];
                --sum[xl[i]][py];
                ++sum[px][py];
            }
        }
        for (int i = n; i >= 1; --i) {
            for (int j = n; j >= 1; --j) {
                sum[i][j] += sum[i + 1][j] + sum[i][j + 1] - sum[i + 1][j + 1];
            }
        }
        for (int i = 1, i2 = i + l - 1; i2 <= n; ++i, ++i2) {
            for (int j = 1, j2 = j + l - 1; j2 <= n; ++j, ++j2) {
                int cur = sum[i][j];
//cerr << l << ' ' << i << ' ' << j << ' ' << cur << endl;
                if (cnt - cur == k || cnt - cur + 1 == k) {
                    printf("1\n");
                    return;
                }
            }
        }
    }
    printf("2\n");
}

int main() {
    solve();
    return 0;
}