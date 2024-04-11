#include <bits/stdc++.h>
using namespace std;

int x;

int main() {
    scanf("%d", &x);
    if (x < 0) x = -x;
    int m;
    for (m = 0; ; m ++) if (m * (m + 1) / 2 >= x) break;
    if ((m * (m + 1) / 2 - x) & 1) {
        if (m & 1) printf("%d\n", m + 2);
        else printf("%d\n", m + 1);
    }
    else printf("%d\n", m);

    return 0;
}