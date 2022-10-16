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

const int N = 8200, INF = 0x3f3f3f3f;

int n, a[N], g[N]; 

vector<int> p[N];

int main() {
    read(n);
    for (int i = 1, x; i <= n; i++) read(x), p[x].pb(i);
    memset(g, 0x3f, sizeof g);
    g[0] = 0;
    for (int x = 1; x <= 5000; x++) {
        if (!p[x].size()) continue;
        for (int i = 0; i < N; i++) {
            if (g[i] == INF) continue;
            if (g[i] < p[x].back()) {
                int pt = upper_bound(p[x].begin(), p[x].end(), g[i]) - p[x].begin();
                int ps = p[x][pt];
                if (ps < g[i ^ x]) {
                    g[i ^ x] = ps;
                }
            }
        }
    }
    int c = 0;
    for (int i = 0; i < N; i++) if (g[i] != INF) c++;
    printf("%d\n", c);
    for (int i = 0; i < N; i++) if (g[i] != INF) printf("%d ", i);
    return 0;
}