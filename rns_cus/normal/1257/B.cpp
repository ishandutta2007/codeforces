#include <bits/stdc++.h>
using namespace std;

#define N 100100

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x >= 4) puts("Yes");
        else if (x == 1) puts(y == 1 ? "Yes" : "No");
        else puts(y <= 3 ? "Yes" : "No");
    }

    return 0;
}