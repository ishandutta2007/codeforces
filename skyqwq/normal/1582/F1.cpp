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

const int N = 1e5 + 5, S = 530;
const int INF = 0x3f3f3f3f;
int n, a[N], f[S][S], suf[N][S];

bool vis[S];
 
int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = n; i; i--) {
        for (int j = 0; j < S; j++) suf[i][j] = suf[i + 1][j];
        suf[i][a[i]] = i;
    }
    memset(f, 0x3f, sizeof f);
    for (int i = 0; i < S; i++)
        if (suf[1][i]) f[i][i] = suf[1][i];
    for (int i = 0; i < S; i++) {
        for (int j = 0; j < S; j++) {
            if (f[i][j] == INF) continue;
            vis[j] = 1;
            int p = f[i][j];
            for (int k = i + 1; k < S; k++) {
                if (suf[p + 1][k]) {
                    chkMin(f[k][j ^ k], suf[p + 1][k]);
                }
            }
        }
    }
    vis[0] = 1;
    int c = 0;
    for (int i = 0; i < S; i++) if (vis[i]) c++;
    printf("%d\n", c);
    for (int i = 0; i < S; i++) if (vis[i]) printf("%d ", i);
    return 0;
}