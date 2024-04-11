#include <bits/stdc++.h>
using namespace std;

#define N 222

int k, a, b;
char s[N];

int main() {
    scanf("%d %d %d %s", &k, &a, &b, s);
    int n = strlen(s);
    if (n < k * a || n > k * b) puts("No solution");
    else {
        n -= k * a, b -= a;
        for (int i = 0, j = 0; s[i]; i ++, j ++) {
            int c = min(n, b) + a;
            if (j >= c) j = 0, n -= min(n, b), puts("");
            putchar(s[i]);
        }
    }

    return 0;
}