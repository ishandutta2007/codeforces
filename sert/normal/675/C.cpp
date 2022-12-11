#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 34;
long long a[N], n, ans, lst;
int main() {
    scanf("%I64d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%I64d", a + i);
        a[i] += a[i - 1];
    }
    sort(a, a + n);
    a[n] = a[n - 1] + 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] != a[i - 1]) {
            ans = max(ans, i - lst);
            lst = i;
        }
    }
    cout << n - ans;
    return 0;
}