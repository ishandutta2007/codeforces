#include <bits/stdc++.h>
using namespace std;
int n, x, y;
long long ans, a[3000], b[3000];
int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &x, &y);
        a[x + y]++;
        b[y - x + 1000]++;
    }
    for (int i = 0; i < 3000; i++)
        ans += a[i] * (a[i] - 1) + b[i] * (b[i] - 1);
    printf("%I64d", ans / 2);
}