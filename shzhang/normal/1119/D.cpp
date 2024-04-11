#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>
#include <iostream>
#include <utility>

using namespace std;

#define ll long long

int n, q;
ll s[100005];
ll max_contrib[100005];
int a[100005];

bool cmp(int x, int y)
{
    return max_contrib[x] < max_contrib[y];
}

ll ans[100005];
pair<ll, int> queries[100005];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    sort(s + 1, s + n + 1);
    for (int i = 1; i < n; i++) {
        max_contrib[i] = s[i+1] - s[i];
    }
    max_contrib[n] = 1000000000000000010LL;
    for (int i = 1; i <= n; i++) a[i] = i;
    sort(a + 1, a + n + 1, cmp);
    cin >> q;
    for (int i = 1; i <= q; i++) {
        ll l, r;
        cin >> l >> r;
        queries[i] = make_pair(r-l+1, i);
    }
    sort(queries + 1, queries + q + 1);
    int acur = 1; /* last one such that max_contrib >= siz */
    ll below_sum = 0; /* sum of max_contrib below siz */
    for (int i = 1; i <= q; i++) {
        while (acur <= n && max_contrib[a[acur]] < queries[i].first) {
            below_sum += max_contrib[a[acur]]; acur++;
        }
        ans[queries[i].second] = below_sum + queries[i].first * (ll)(n - acur + 1);
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}