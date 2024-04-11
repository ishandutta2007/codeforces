#include <bits/stdc++.h>
using namespace std;

#define N 100005

int n;
int p[N];

bool f(int x) {
    if (!x) return 0;
    int y = 1;
    while (y <= x) y <<= 1;
    int z = y - x - 1;
    for (int i = z; i <= x; i ++) p[i] = x + z - i;
    f(z - 1);
}

bool F(int n) {
    if (n & 1) {
        return puts("NO");
    }
    puts("YES");
    f(n);
    for (int i = 1; i <= n; i ++) printf("%d ", p[i]);
    puts("");
}

bool g(int x) {
    if (x == 7) {
        p[1] = 3, p[2] = 6, p[3] = 1, p[4] = 5, p[5] = 4, p[6] = 7, p[7] = 2;
        return 0;
    }
    int y = 1;
    while ((y << 1) <= x) y <<= 1;
    for (int i = y, j = y + 1; i <= x; i ++, j ++) {
        if (j == x + 1) j = y;
        p[i] = j;
    }
    g(y - 1);
}

bool G(int n) {
    if (n <= 5 || __builtin_popcount(n) == 1) return puts("NO");
    puts("YES");
    if (n == 6) return puts("3 6 1 5 4 2\n");
    g(n);
    for (int i = 1; i <= n; i ++) printf("%d ", p[i]);
}

int main() {
    scanf("%d", &n);
    F(n), G(n);
    return 0;
}