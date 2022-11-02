#include <bits/stdc++.h>
using namespace std;

#define N 200005

int n, m, a[N], b;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i ++) scanf("%d", a + i);
    sort(a, a + n);
    while (m --) {
        scanf("%d", &b);
        int p = upper_bound(a, a + n, b) - a;
        printf("%d ", p);
    }
}