#include <bits/stdc++.h>
using namespace std;

#define N 300300

int n, m, a[N], b[N];

bool check(int k) {
    int cur = m - 1;
    for (int i = n; i; i --) {
        if (a[i] <= cur) {
            b[i] = min(cur, a[i] + k);
            cur = b[i];
        }
        else if (a[i] + k < m) return 0;
        else b[i] = min(cur, a[i] + k - m), cur = b[i];
    }
    return 1;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    int l = 0, r = m - 1;
    while (l < r) {
        int mi = l + r >> 1;
        if (check(mi)) r = mi;
        else l = mi + 1;
    }
    printf("%d\n", l);
}