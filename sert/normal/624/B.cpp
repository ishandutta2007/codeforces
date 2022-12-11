#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a[34];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    sort(a, a + n);
    long long sum = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        a[i] = max(0, min(a[i], a[i + 1] - 1));
        sum += a[i];
    }
    printf("%I64d", sum);
}