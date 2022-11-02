#include <bits/stdc++.h>
using namespace std;

#define N 111
int n, a[N];

int main() {
    int x, y, z = 1e9;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for (int i = 1, j = 2; i <= n; i ++, j ++) {
        if (j > n) j = 1;
        int c = abs(a[i] - a[j]);
        if (c < z) z = c, x = i, y = j;
    }
    printf("%d %d\n", x, y);

    return 0;
}