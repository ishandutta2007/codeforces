#include <bits/stdc++.h>
using namespace std;

#define N 200005

int n, k, a[N];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i ++) scanf("%d", a + i);
    sort(a, a + n);
    if (k == n) printf("%d", a[n-1]);
    else if (!k) {
        if (a[0] == 1) puts("-1");
        else printf("%d", a[0] - 1);
    }
    else {
        if (a[k-1] < a[k]) printf("%d", a[k-1]);
        else puts("-1");
    }
}