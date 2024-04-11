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

int
main()
{
    ios_base::sync_with_stdio(false);
    int l, r;
    cin >> l >> r;
    int base_w = l - 1;
    l -= base_w;
    r -= base_w;
    int n = 2;
    while ((1 << (n - 1)) < r) ++n;
    ve<tu<int, int, int>> g;
    for (int i = 0; i < n; ++i) {
        int from_w = (i == 0) ? 1 : (1 << (i - 1));
        for (int j = i + 1; j < n; ++j) {
            g.emplace_back(i, j, from_w);
        }
    }
    for (int i = n - 1; i >= 1; --i) {
        if ((1 << (i - 1)) < r) {
            int diff = r - (1 << (i - 1));
            g.emplace_back(i, n, base_w + diff);
            r = diff;
        }
    }
    g.emplace_back(0, n, base_w + 1);
    cout << "YES\n";
    cout << n + 1 << " " << g.size() << '\n';
    for (auto [u, v, w] : g) {
        cout << u + 1 << ' ' << v + 1 << ' ' << w << '\n';
    }
    return 0;
}