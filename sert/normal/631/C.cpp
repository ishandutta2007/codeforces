#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 34;
typedef long long ll;
typedef long double ld;

int a[N], b[N], sf[N], n, m, t[N], r[N];

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++) {
        cin >> t[i] >> r[i];
    }
    t[n] = 1;

    sf[n] = 0;
    for (int i = m - 1; i >= 0; i--)
        sf[i] = max(r[i], sf[i + 1]);

    int cur = sf[0];

    sort(a, a + cur);
    int l = 0;
    int r = cur - 1;

    for (int i = cur; i < n; i++)
        b[i] = a[i];

    for (int i = 0; i < m; i++)
    if (sf[i + 1] < cur) {
        if (t[i] == 2) {
            for (int j = sf[i + 1]; j < cur; j++)
                b[j] = a[l + cur - j - 1];
            l += cur - sf[i + 1];
        } else {
            for (int j = sf[i + 1]; j < cur; j++)
                b[j] = a[r + j + 1 - cur];
            r -= cur - sf[i + 1];
        }
        cur = sf[i + 1];
    }

    for (int i = 0; i < n; i++)
        cout << b[i] << " ";

    return 0;
}