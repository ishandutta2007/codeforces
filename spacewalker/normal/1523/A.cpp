#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 2000;
constexpr int INF = 1100000000;

void solve() {
    static char init[NMAX];
    static char dst[NMAX];
    memset(init, 0, sizeof init);
    memset(dst, 0, sizeof dst);
    int n, m; scanf("%d %d", &n, &m);
    scanf("%s", init);
    vector<int> ldist(n, -1), rdist(n, -1);
    for (int i = 0; i < n; ++i) {
        if (init[i] == '1') ldist[i] = 0;
        else if (i > 0 && ldist[i-1] != -1) ldist[i] = ldist[i-1] + 1;
    }
    for (int i = n-1; i >= 0; --i) {
        if (init[i] == '1') rdist[i] = 0;
        else if (i < n - 1 && rdist[i+1] != -1) rdist[i] = rdist[i+1] + 1;
    }
    for (int i = 0; i < n; ++i) {
        if (ldist[i] == -1) ldist[i] = INF;
        if (rdist[i] == -1) rdist[i] = INF;
    }
    for (int i = 0; i < n; ++i) {
        if (ldist[i] == 0) dst[i] = '1';
        else if (ldist[i] == rdist[i]) dst[i] = '0';
        else if (min(ldist[i], rdist[i]) <= m) dst[i] = '1';
        else dst[i] = '0';
    }
    printf("%s\n", dst);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) solve();
}