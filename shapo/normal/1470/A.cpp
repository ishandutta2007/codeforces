#include <bits/stdc++.h>

using namespace std;

#define ve vector

typedef ve<int> vi;
typedef long long ll;

void
solve()
{
    int n, m;
    cin >> n >> m;
    vi k(n);
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
        --k[i];
    }
    sort(k.rbegin(), k.rend());
    vi c(m);
    for (int i = 0; i < m; ++i) {
        cin >> c[i];
    }
    ll ans = 0ll;
    for (int i = 0, j = 0; i < n; ++i) {
        if (j <= k[i]) {
            ans += c[j];
            j++;
        } else {
            ans += c[k[i]];
        }
    }
    cout << ans << '\n';
}

int
main()
{
    cin.sync_with_stdio(false);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        solve();
    }
    return 0;
}