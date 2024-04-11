#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, m, x[N];
typedef pair <int, int> pii;
pii p[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        int l;
        pii a = pii(-1, -1);
        scanf("%d", &l);
        int lst = 1e7, fg = 0;
        while (l --) {
            int x;
            scanf("%d", &x);
            if (a.first < 0) a.first = x;
            a.second = x;
            if (x > lst) fg = 1;
            lst = x;
        }
        swap(a.first, a.second);
        if (!fg) p[m++] = a;
    }
    sort(p, p + m);
    long long ans = 1ll * n * n;
    for (int i = 0; i < m; i ++) x[i] = p[i].second;
    sort(x, x + m);
    for (int i = 0; i < m; i ++) ans -= upper_bound(x, x + m, p[i].first) - x;
    printf("%I64d\n", ans);

    return 0;
}