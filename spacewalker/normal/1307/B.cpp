#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, x; scanf("%d %d", &n, &x);
        int best = 0;
        set<int> yeeters;
        for (int i = 0; i < n; ++i) {
            int y; scanf("%d", &y);
            best = max(best, y);
            yeeters.insert(y);
        }
        int ans = x/best + (x % best == 0 ? 0 : 1);
        ans = max(2, ans);
        if (yeeters.count(x) > 0) ans = 1;
        printf("%d\n", ans);
    }
    return 0;
}