#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
typedef pair<int, int> P;
typedef long long ll;
const int F = (int)1e4 + 50, N = (int)1e5 + 50, INF = (int)2e9;
using namespace __gnu_pbds;

typedef tree<
        pair<int, int>,
        null_type,
        less<>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        my_tree;

my_tree tr[F];
int n, k;

struct St {
    int x, r, f;

    void read() {
        cin >> x >> r >> f;
    }
} sts[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i < n; i++) sts[i].read();
    sort(sts, sts + n, [](const St &s1, const St &s2) {
        return s1.r > s2.r;
    });
    ll res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = max(1, sts[i].f - k); j <= min(F - 1, sts[i].f + k); j++) {
            res += tr[j].order_of_key({sts[i].x + sts[i].r, INF}) -
                    tr[j].order_of_key({sts[i].x - sts[i].r, -1});
        }
        tr[sts[i].f].insert({sts[i].x, i});
    }
    cout << res << endl;
}