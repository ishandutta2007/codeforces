#include <bits/stdc++.h>
using namespace std;

#define N 200100

int n, a[N], b[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), b[i] = 0;
        int rlt = n + 1;
        for (int i = 1; i <= n; i ++) {
            int c = a[i];
            if (b[c]) rlt = min(rlt, i - b[c] + 1);
            b[c] = i;
        }
        if (rlt > n) rlt = -1;
        printf("%d\n", rlt);
    }

    return 0;
}