#include <bits/stdc++.h>

using namespace std;

#define ve vector
#define pa pair
#define tu tuple

typedef uint32_t uint;
typedef int64_t ll;

typedef ve<int> vi;
typedef ve<vi> v2i;
typedef pa<int, int> pii;

void
solve()
{
    int n;
    cin >> n;
    ve<ll> s(n), sm(n, 0ll);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        res += max(0ll, s[i] - 1ll - sm[i]);
        for (int j = 2; j <= s[i] && i + j < n; ++j) {
            sm[i + j]++;
        }
        if (i < n - 1) {
            sm[i + 1] += max(0ll, sm[i] - (s[i] - 1ll));
        }
    }
    cout << res << '\n';
}

int
main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}