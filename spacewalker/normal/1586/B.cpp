#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m; scanf("%d %d", &n, &m);
    vector<bool> isCenter(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        isCenter[b - 1] = true;
    }
    int root = -1;
    for (int i = 0; i < n; ++i) if (!isCenter[i]) root = i;
    assert(root != -1);
    for (int i = 0; i < n; ++i) {
        if (i == root) continue;
        printf("%d %d\n", root + 1, i + 1);
    }
}

int main() {
    int t; scanf("%d", &t);
    while (t--) solve();
}