#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
typedef pair<int, int> P;
typedef long long ll;
using namespace __gnu_pbds;
const int N = (int)1e5 + 50, INF = (int)1e9 + 50;

typedef tree<
        pair<int, int>,
        null_type,
        less<>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        my_tree;

map<int, my_tree> mp;

int n, k;
int id[N];
int x[N], r[N], q[N];

bool cmp(int i, int j) {
    return r[i] > r[j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll res = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> x[i] >> r[i] >> q[i], id[i] = i;
    sort(id, id + n, cmp);
    for(int ki = 0; ki < n; ki++) {
        int i = id[ki];
        for(int j = q[i] - k; j <= q[i] + k; j++) {
            if(!mp.count(j)) continue;
            auto &tree = mp[j];
            res += tree.order_of_key({x[i] + r[i], INF}) - tree.order_of_key({x[i] - r[i], -INF});
        }
        mp[q[i]].insert({x[i], i});
    }
    cout << res << endl;
}