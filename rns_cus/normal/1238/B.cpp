#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, r, x[N];

int main() {
    int q;
    scanf("%d", &q);
    while (q --) {
        scanf("%d %d", &n, &r);
        for (int i = 1; i <= n; i ++) scanf("%d", &x[i]);
        sort(x + 1, x + n + 1);
        int ans = 0;
        for (int i = n, j = n; i; i = j) {
            if (x[i] <= 1ll * r * ans) break;
            while (j && x[j] == x[i]) j --;
            ans ++;
        }
        printf("%d\n", ans);
    }
}