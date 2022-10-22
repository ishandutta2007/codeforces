#include <bits/stdc++.h>
using namespace std;
int n, k, c[10100], pre[110], vis[110];
int L[110], R[110];

int main() {
    cin >> n >> k;
    int m = n * k;
    for (int i = 1; i <= m; i++)
        cin >> c[i];
    int lim = (n + k - 2) / (k - 1);
    while (lim--) {
        memset(pre, 0, sizeof(pre));
        for (int i = 1; i <= m; i++) {
            if (!vis[c[i]]) {
                if (pre[c[i]]) {
                    L[c[i]] = pre[c[i]];
                    R[c[i]] = i;
                    vis[c[i]] = 1;
                    memset(pre, 0, sizeof(pre));
                }
                else
                    pre[c[i]] = i;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d %d\n", L[i], R[i]);
    return 0;
}