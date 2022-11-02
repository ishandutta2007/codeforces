#include <bits/stdc++.h>
using namespace std;

#define N 300100

int n, a[N], pos[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) pos[i] = 0, scanf("%d", &a[i]);
        for (int i = 1; i <= n; i ++) {
            if (pos[a[i]] > 0) pos[a[i]] = -1;
            else if (pos[a[i]] == 0) pos[a[i]] = i;
        }
        bool first = true;
        for (int i = 1; i <= n; i ++) if (pos[i] <= 0) first = false;
        if (first) putchar('1');
        else putchar('0');
        int k = 1, l = 1, r = n;
        while (k <= n && pos[k] > 0) {
            if (pos[k] == l) l ++;
            else if (pos[k] == r) r --;
            else break;
            k ++;
        }
        if (l <= r && pos[k] != 0) k ++;
        for (int i = 2; i <= n; i ++) if (i >= n + 2 - k) putchar('1'); else putchar('0'); puts("");

    }

    return 0;
}