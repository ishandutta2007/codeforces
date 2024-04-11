#include <bits/stdc++.h>
using namespace std;

#define N 100100
int n, a[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
    sort(a, a + n);
    int k; bool fg = 0;
    for (k = 0; k < n - 1; k ++) if (a[k] == a[k+1]) break;
    if (k < n - 1) {
        fg = 1; if (!a[k]) return puts("cslnb"), 0;
        a[k] --;
        sort(a, a + n);
        for (k = 0; k < n - 1; k ++) if (a[k] == a[k+1]) return puts("cslnb"), 0;
    }
    int rlt = fg;
    for (int i = 0; i < n; i ++) rlt ^= (a[i] + i & 1);
    if (rlt) puts("sjfnb");
    else puts("cslnb");

    return 0;
}