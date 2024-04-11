#include <bits/stdc++.h>
int n, a[3000], b[3000], ps;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    b[ps++] = a[0];
    for (int i = 1; i < n; i++) {
        if (std::__gcd(a[i - 1], a[i]) > 1)
            b[ps++] = 1;
        b[ps++] = a[i];
    }
    printf("%d\n", ps - n);
    for (int i = 0; i < ps; i++)
        printf("%d ", b[i]);
    return 0;
}