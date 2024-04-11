#include <bits/stdc++.h>
using namespace std;

#define N 300100

int n, a[N], pre[N], suf[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
        puts(a[1] < a[n] ? "YES" : "NO");

    }

    return 0;
}