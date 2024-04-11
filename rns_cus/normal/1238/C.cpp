#include <bits/stdc++.h>
using namespace std;

#define N 200200

int n, h, x[N];

int main() {
    int q;
    scanf("%d", &q);
    while (q --) {
        scanf("%d %d", &h, &n);
        int ans = 0;
        for (int i = 1; i <= n; i ++) scanf("%d", &x[i]);
        x[0] = h + 1;
        for (int i = 0, j; i <= n; i = j) {
            for (j = i + 1; j <= n && x[j] == x[j-1] - 1; j ++);
            if (j > n && x[n] == 1) continue;
            if (j - i & 1) ans ++;
        }
        printf("%d\n", ans);
    }
}