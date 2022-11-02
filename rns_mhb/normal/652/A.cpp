#include <bits/stdc++.h>
using namespace std;

int main() {
    int h1, h2, a, b;
    scanf("%d %d %d %d", &h1, &h2, &a, &b);
    if (h1 + 8 * a >= h2) puts("0");
    else if (a > b) {
        int sh = 12 * (a - b), lh = h2 - h1 - 8 * a;
        printf("%d\n", (lh + sh - 1) / sh);
    }
    else puts("-1");
    return 0;
}