#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#include <bits/stdc++.h>

using namespace std;

const int MaxN = 64;

int p[MaxN][MaxN][MaxN], psz[MaxN][MaxN], g[MaxN][MaxN], gsz[MaxN];
int n, m, ord[MaxN << 2], stk[MaxN << 2], osz, ssz, IT;

void Go(int v) {
    if (ssz > 2 * n + 1 || osz >= 2 * n + 1 || ++IT >= 10000) {
        return;
    }
    if (osz < ssz && stk[osz] != v) {
        return;
    }
    ord[osz++] = v;
    if (osz == ssz) {
        printf("%d\n", ssz);
        for (int i = 0; i < ssz; ++i) {
            printf("%d%c", stk[i], i == ssz - 1 ? '\n' : ' ');
        }
        printf("\n");
        exit(0);
    }
    if (osz < ssz) {
        if (~psz[v][stk[osz]]) {
            int to = stk[osz];
            int len = ssz;
            for (int i = 0; i < psz[v][to]; ++i) {
                stk[ssz + i] = p[v][to][i];
            }
            ssz += psz[v][to];
            Go(to);
            ssz = len;
        }
    } else {
        for (int it = 0; it < gsz[v]; ++it) {
            int to = g[v][it];
            bool ok = true;
            if (osz > ssz) {
                for (int i = ssz, j = 0; j < psz[v][to] && i < osz && ok; ++i, ++j) {
                    ok &= p[v][to][j] == ord[i];
                }
            }
            if (ok) {
                int len = ssz;
                for (int i = 0; i < psz[v][to]; ++i) {
                    stk[ssz + i] = p[v][to][i];
                }
                ssz += psz[v][to];
                Go(to);
                ssz = len;
            }
        }
    }
    --osz;
}

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    memset(psz, -1, sizeof(psz));
    for (int j = 1; j <= m; ++j) {
        int x, y;
        scanf("%d%d", &x, &y);
        int s;
        scanf("%d", &s);
        psz[x][y] = s;
        g[x][gsz[x]++] = y;
        for (int i = 0; i < s; ++i) {
            scanf("%d", &p[x][y][i]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        sort(g[i], g[i] + gsz[i], [&](int x, int y) {
                return psz[i][x] > psz[i][y];
             });
    }
    for (int i = 1; i <= n; ++i) {
        IT = osz = ssz = 0;
        Go(i);
    }
    printf("0\n");
    return 0;
}