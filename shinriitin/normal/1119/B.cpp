#include <bits/stdc++.h>

const int max_N = 1000 + 21;

int n, h, a[max_N], b[max_N], ans;

int main() {
    scanf("%d%d", &n, &h);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    for (int k = 1; k <= n; ++k) {
        b[k] = a[k];
        for (int j = k - 1; j; --j) {
            if (b[j] <= b[j + 1]) break;
            std::swap(b[j], b[j + 1]);
        }
        bool flag = true;
        int sum = 0;
        for (int j = k; j > 0; j -= 2) {
            sum += b[j];
            if (sum > h) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans = std::max(ans, k);
        }
    }
    printf("%d\n", ans);
}