#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 34;

ll d[1 << 18][18];
ll c[18][18];
ll a[18], n, m, k, ans, v1, v2, cst, new_mask;
int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < k; i++) {
        cin >> v1 >> v2 >> cst;
        c[v1 - 1][v2 - 1] = cst;
    }
    for (int i = 0; i < n; i++)
        d[1 << i][i] = a[i];
    for (int mask = 0; mask < (1 << n); mask++) 
        for (int v = 0; v < n; v++) {
            if ((mask & (1 << v)) == 0)
                continue;
            if (__builtin_popcount(mask) == m) {
                ans = max(ans, d[mask][v]);
                continue;
            }
            for (int w = 0; w < n; w++) {
                if (mask & (1 << w))
                    continue;
                new_mask = (mask | (1 << w));
                d[new_mask][w] = max(d[new_mask][w], d[mask][v] + a[w] + c[v][w]);
            }
        }
    cout << ans;
    return 0;
}