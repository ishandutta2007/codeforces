#include <bits/stdc++.h>
using namespace std;

#define N 111

int n, a[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
        for (int i = 1; i <= n; i ++) {
            a[i] = abs(a[i]);
            if (i & 1) a[i] = -a[i];
            printf("%d ", a[i]);
        }
        puts("");
    }

    return 0;
}