#include <bits/stdc++.h>

using namespace std;


int main() {
    int n; scanf("%d", &n);
    vector<int> perm(n);
    for (int i = 0; i < n; ++i) scanf("%d", &perm[i]);
    vector<vector<int>> ans(n, vector<int>(n, -1));
    for (int i = 0; i < n; ++i) {
        int cx = i, cy = i;
        for (int steps = 0; steps < perm[i]; ++steps) {
            ans[cx][cy] = perm[i];
            if (steps + 1 < perm[i]) {
                if (cy > 0 && ans[cx][cy-1] == -1) --cy;
                else ++cx;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}