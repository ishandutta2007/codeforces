#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 3e5 + 5, M = 19;

int n, m, f[M][N][2][2];
bool used[N];

void dfs(int d, int u) {
    int l = u << 1, r = u << 1 | 1;
    f[d][u][0][0] = -1e9;
    f[d][u][0][1] = -1e9;
    f[d][u][1][0] = -1e9;
    f[d][u][1][1] = -1e9;
    if (d == n - 1) {
        int now = used[l] | used[r];
        f[d][u][used[l]][used[r]] = now;
        f[d][u][used[r]][used[l]] = now;
        return;
    } else {
        dfs(d + 1, l); dfs(d + 1, r);
        for (int li = 0; li <= 1; li++) {
            for (int lj = 0; lj <= 1; lj++) {
                for (int ri = 0; ri <= 1; ri++) {
                    for (int rj = 0; rj <= 1; rj++) {
                        int iw, il, jw, jl, kw, kl;
                        for (int x = 0; x <= 1; x++) {
                            if (x == 0) {
                                iw = li; il = ri;
                            } else {
                                iw = ri; il = li;
                            }
                            for (int y = 0; y <= 1; y++) {
                                if (y == 0) {
                                    jw = lj; jl = rj;
                                } else {
                                    jw = rj; jl = lj;
                                }
                                for (int z = 0; z <= 1; z++) {
                                    if (z == 0) {
                                        kw = il; kl = jw;
                                    } else {
                                        kw = jw; kl = il;
                                    }
                                    int now = (li | ri) + (lj | rj) + (il | jw);
                                    f[d][u][iw][kw] = std::max(f[d][u][iw][kw], now + f[d + 1][l][li][lj] + f[d + 1][r][ri][rj]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int main() {
    n = read(); m = read();
    for (int i = 0; i < m; i++) {
        int x = read(); x--;
        used[x] = true;
    }
    dfs(0, 0);
    printf("%d\n", std::max(std::max(std::max(f[0][0][0][0], f[0][0][0][1] + 1), f[0][0][1][0] + 1), f[0][0][1][1] + 1));
    return 0;
}