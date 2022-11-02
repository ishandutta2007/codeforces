#include <bits/stdc++.h>
using namespace std;


int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        int p = abs(a - c) + abs(b - d);
        if (a != c && b != d) p += 2;
        printf("%d\n", p);
    }

    return 0;
}