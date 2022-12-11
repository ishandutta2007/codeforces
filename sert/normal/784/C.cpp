#include <bits/stdc++.h>
int main() {
    int n, a[20];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    printf("%d", *std::max_element(a, a + n) ^ a[n - 1]);
}