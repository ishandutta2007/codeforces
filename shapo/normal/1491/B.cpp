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
    int n, u, v;
    cin >> n >> u >> v;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int res = min(2 * v, u + v);
    for (int i = 0; i + 1 < n; ++i) {
        int dist = abs(a[i] - a[i + 1]);
        if (dist >= 2) {
            res = min(res, 0);
        } else if (dist == 1) {
            res = min(res, min(u, v));
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