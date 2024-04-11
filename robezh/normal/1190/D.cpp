#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;

typedef long long ll;

const int N = (int)2e5 + 50, INF = (int)1e9 + 50;
using namespace __gnu_pbds;

typedef tree<
        int,
        null_type,
        less<>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set ;

int n;
struct P {
    int x, y;
} p[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    sort(p, p + n, [](const P &p1, const P &p2) {
        return p1.y != p2.y ? p1.y > p2.y : p1.x < p2.x;
    });
//    set<int> S;
    ordered_set S;

    ll res = 0;
    for(int i = 0, r = 0; i < n; i = r) {
        while(r < n && p[r].y == p[i].y) r++;
        int la = -INF;
        for(int j = i; j < r; j++) {
            ll len = S.order_of_key(p[j].x) - S.order_of_key(la + 1);
            res -= (len + 1) * len / 2;
            la = p[j].x;
            S.insert(p[j].x);
        }
        ll len = S.order_of_key(INF) - S.order_of_key(la + 1);
        res -= (len + 1) * len / 2;
        ll sz = S.size();
        res += (sz + 1) * sz / 2;
    }
    cout << res << endl;
}