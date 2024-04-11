#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 200010;

char prog[NMAX];

void solve() {
    int n, m; scanf("%d %d", &n, &m);
    scanf("%s", prog);
    vector<int> maxfs(n), minfs(n), locto(n);
    int cloc = 0;
    for (int i = 0; i < n; ++i) {
        cloc += (prog[i] == '+' ? 1 : -1);
        maxfs[i] = max(i > 0 ? maxfs[i-1] : 0, cloc);
        minfs[i] = min(i > 0 ? minfs[i-1] : 0, cloc);
        locto[i] = cloc;
    }
    vector<int> maxte(n), minte(n);
    for (int i = n - 1; i >= 0; --i) {
        int d = prog[i] == '+' ? 1 : -1;
        maxte[i] = max((i < n - 1 ? maxte[i+1] : 0) + d, 0);
        minte[i] = min((i < n - 1 ? minte[i+1] : 0) + d, 0);
    }
    for (int qta = 0; qta < m; ++qta) {
        int l, r; scanf("%d %d", &l, &r); --l; --r;
        if (l == 0) {
            if (r == n - 1) printf("1\n");
            else printf("%d\n", maxte[r+1] - minte[r+1] + 1);
        } else if (r == n - 1) {
            printf("%d\n", maxfs[l-1] - minfs[l-1] + 1);
        } else {
            int tmax = max(maxfs[l-1], locto[l-1] + maxte[r+1]),
                tmin = min(minfs[l-1], locto[l-1] + minte[r+1]);
            printf("%d\n", tmax - tmin + 1);
        }
    }
}

int main() {
    int t; scanf("%d", &t);
    while (t--) solve();
    return 0;
}