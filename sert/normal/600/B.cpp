#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 34;
int n, m, x, a[N];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    sort(a, a + n);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        printf("%d ", upper_bound(a, a + n, x) - a);
    }

}