//made by Sert
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;

int n, k;
ll l, r, m;
ll cur;
ll a[N], b[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%I64d", a + i);
    for (int i = 0; i < n; i++) scanf("%I64d", b + i);

    l = 0;
    r = 3e9;

    while (r - l > 1) {
        m = (l + r) / 2;
        cur = 0;
        for (int i = 0; i < n && cur <= k; i++) {
            cur += max(0ll, a[i] * m - b[i]);
        }
        if (cur <= k)
            l = m;
        else
            r = m;
    }
    cout << l;

    return 0;
}