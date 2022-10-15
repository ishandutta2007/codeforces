#include <cstdio>

int n, m, ans, a[300005];

bool check(int x) {
    int lst = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] <= lst) {
            if (a[i] + x < lst) { return false; }
        } else {
            if (a[i] + x < lst + m) { lst = a[i]; }
        }
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) { scanf("%d", &a[i]); }
    for (int l = 0, r = m - 1, mid; l <= r; ) {
        mid = l + r >> 1;
        if (check(mid)) { ans = mid; r = mid - 1; }
        else { l = mid + 1; }
    }
    printf("%d\n", ans);
    return 0;
} //