#include <bits/stdc++.h>
using namespace std;

#define N 111

int cnt[N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    while (m --) {
        int a, b;
        scanf("%d %d", &a, &b);
        for (int i = a; i <= b; i ++) cnt[i] ++;
    }
    int k;
    for (k = 1; k <= n; k ++) if (cnt[k] != 1) break;
    if (k > n) puts("OK");
    else printf("%d %d\n", k, cnt[k]);

    return 0;
}