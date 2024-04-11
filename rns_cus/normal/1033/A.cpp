#include <bits/stdc++.h>
using namespace std;

int n, a[2], b[2], c[2];

int sign(int x) {
    return x / abs(x);
}

int main() {
    scanf("%d", &n);
    scanf("%d %d %d %d %d %d", &a[0], &a[1], &b[0], &b[1], &c[0], &c[1]);
    b[0] -= a[0], b[1] -= a[1];
    c[0] -= a[0], c[1] -= a[1];
    if (sign(b[0]) != sign(c[0]) || sign(b[1]) != sign(c[1])) puts("NO");
    else puts("YES");

    return 0;
}