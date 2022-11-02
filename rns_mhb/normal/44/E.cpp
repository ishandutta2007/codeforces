#include <bits/stdc++.h>
using namespace std;

#define N 205

int k, a, b, n;
char s[N];

int main() {
    scanf("%d %d %d %s", &k, &a, &b, s);
    n = strlen(s);
    if (n < k * a || n > k * b) return puts("No solution"), 0;
    int r = n - k * a;
    for (int i = 0, j; i < k; i ++) {
        int c = a + min(r, b - a);
        r -= min(r, b - a);
        while (c --) putchar(s[j++]);
        putchar('\n');
    }
    return 0;
}