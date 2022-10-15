#include <cstdio>
#include <algorithm>

int n, ans, a[200005], f[200005];

int main() {
    scanf("%d", &n); f[n + 1] = -1e9;
    for (int i = 1; i <= n; i++) { scanf("%d", &a[i]); f[a[i]] = -1e9; }
    for (int i = 1; i <= n; i++) { scanf("%d", &a[i]); f[a[i]] = i - a[i] + 1; }
    for (int i = 1, j = 0; i <= n + 1; i++) {
        if (a[i] == 1) { j = i; } else if (j) {
            if (i == n + 1) {
                if (*std::max_element(f + n - j + 2, f + n + 2) <= j - n - 1) { printf("%d\n", j - 1); return 0; }
            } else if (a[i] - i != a[j] - j) { break; }
        }
    }
    printf("%d\n", *std::max_element(f + 1, f + n + 3) + n);
    return 0;
}