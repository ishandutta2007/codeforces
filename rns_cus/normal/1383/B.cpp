#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, a[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        int tot = 0;
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &a[i]);
            tot ^= a[i];
        }
        if (tot == 0) puts("DRAW");
        else {
            int k = __lg(tot);
            int x = 0, y = 0;
            for (int i = 1; i <= n; i ++) {
                if (a[i] >> k & 1) x ++;
                else y ++;
            }
            x >>= 1;
            if (x & 1) {
                if (y & 1) puts("WIN");
                else puts("LOSE");
            }
            else puts("WIN");
        }
    }

    return 0;
}