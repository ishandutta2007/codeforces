#include <cstdio>
#include <algorithm>

int n, a[100005];

void flip(int &x) { x = -x - 1; }

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] >= 0) { flip(a[i]); }
    }
    if (n & 1) { flip(*std::min_element(a + 1, a + n + 1)); }
    for (int i = 1; i <= n; i++) { printf("%d ", a[i]); }
    return 0;
}