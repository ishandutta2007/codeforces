#include <bits/stdc++.h>
using namespace std;

#define N 200200

int n, a[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i ++) scanf("%d", &a[i]);
    sort(a, a + 2 * n);
    long long ans = 1ll * (a[n-1] - a[0]) * (a[2*n-1] - a[n]);
    for (int i = 1; i < n; i ++) {
        ans = min(ans, 1ll * (a[2*n-1] - a[0]) * (a[i+n-1] - a[i]));
    }
    cout << ans << endl;

    return 0;
}