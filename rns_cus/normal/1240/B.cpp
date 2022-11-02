#include <bits/stdc++.h>
using namespace std;

#define N 300200

int n, a[N], m, x[N], le[N], ri[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n); m = 0;
        for (int i = 0; i < n; i ++) scanf("%d", &a[i]), x[m++] = a[i];
        sort(x, x + m); m = unique(x, x + m) - x;
        for (int i = 0; i < n; i ++) a[i] = lower_bound(x, x + m, a[i]) - x;
        for (int i = 0; i < m; i ++) le[i] = n, ri[i] = -1;
        for (int i = 0; i < n; i ++) le[a[i]] = min(le[a[i]], i), ri[a[i]] = max(ri[a[i]], i);
        int rlt = 0;
        for (int i = 0, j = 0; i < m; i = j) {
            for (j ++; j < m && le[j] > ri[j-1]; j ++);
            rlt = max(rlt, j - i);
        }
        printf("%d\n", m - rlt);
    }
}