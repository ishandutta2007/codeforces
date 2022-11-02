#include <bits/stdc++.h>
using namespace std;

#define N 300100
int n, a[N];

int main() {
    scanf("%d", &n);
    long long p = 0, q = 0;
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        int x = a[i] >> 1, y = a[i] - x;
        if (i & 1) p += x, q += y;
        else p += y, q += x;
    }

    printf("%I64d\n", min(p, q));
    return 0;
}