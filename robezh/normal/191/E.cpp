#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;
typedef pair<int, int> P;
typedef long long ll;
const int N = (int)1e5 + 50;
const ll INF = (ll)1e18;

typedef tree<
        pair<ll, int>,
        null_type,
        greater<>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        rb_tree;

int n;
ll k;
int num[N];

ll get_rank(ll x) {
    rb_tree tree;
    ll off = 0, rk = 0;
    for(int i = n - 1; i >= 0; i--) {
        off += num[i];
        tree.insert({num[i] - off, i});
        rk += tree.order_of_key({x - off, -INF});
    }
    return rk + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> num[i];
    ll l = -INF, r = INF, mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        if(get_rank(mid) <= k) r = mid;
        else l = mid;
    }
    cout << r << endl;
}