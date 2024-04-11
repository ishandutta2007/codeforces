#include <bits/stdc++.h>
using namespace std;

#define N 55

int n, m, a[N][N];

typedef pair <int, int> pii;
vector <pii> ans;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (a[i][j]) {
                if (i < n && j < m) {
                    bool fg = 1;
                    for (int k = 0; k < 2; k ++)
                        for (int l = 0; l < 2; l ++)
                            if (!a[i+k][j+l]) fg = 0;
                    if (!fg && a[i][j] == 1) return puts("-1"), 0;
                    if (fg) {
                        ans.emplace_back(i, j);
                        for (int k = 0; k < 2; k ++) for (int l = 0; l < 2; l ++) a[i+k][j+l] = 2;
                    }
                }
                else if (a[i][j] == 1) return puts("-1"), 0;
            }
        }
    }
    int sz = ans.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; i ++) printf("%d %d\n", ans[i].first, ans[i].second);

    return 0;
}