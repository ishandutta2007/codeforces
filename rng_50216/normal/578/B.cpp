#include <bits/stdc++.h>

using namespace std;

int const N = 1234567;

int a[N], b[N], c[N];

int main() {
    int n, k, x;
    scanf("%d%d%d", &n, &k, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        b[i] = c[i] = a[i];
    }
    for (int i = 1; i < n; i++) b[i] |= b[i - 1];
    for (int i = n - 2; i >= 0; i--) c[i] |= c[i + 1];
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long f = a[i];
        for (int j = 0; j < k; j++) f *= x;
        if (i > 0) f |= b[i - 1];
        if (i + 1 < n) f |= c[i + 1];
        if (ans < f) ans = f;
    }
    cout << ans << endl;
}