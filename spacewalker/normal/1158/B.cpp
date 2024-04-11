#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, n; scanf("%d %d", &n, &k);
    if (k == 1) {
        for (int i = 0; i < n; ++i) printf("%c", i == 0 ? '1' : '0');
    } else if (k == n) {
        for (int i = 0; i < n; ++i) printf("1");
    } else {
        int period = (n - k) / 2 + 1;
        if (2 * period <= n) {
            for (int i = 0; i < n; ++i) printf("%c", i % period == 0 ? '1' : '0');
        } else {
            for (int i = 0; i < n; ++i) printf("%c", (i == k - 2) || (i == 2 * k - 3)  ? '1' : '0');
        }
    }
    printf("\n");
    return 0;
}