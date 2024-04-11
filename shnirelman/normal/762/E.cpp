#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define f first
#define s second

using namespace std;
using namespace __gnu_pbds;
//using namespace pb_ds;
using li = long long;
using pii = pair<int, int>;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int A = 1e4 + 13;

ordered_set st[A];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pair<pii, int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].f.s >> a[i].f.f >> a[i].s;
    }

    sort(a.rbegin(), a.rend());

    li ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = max(0, a[i].s - k); j <= a[i].s + k; j++) {
            ans += st[j].order_of_key(a[i].f.s + a[i].f.f + 1) - st[j].order_of_key(a[i].f.s - a[i].f.f);
        }

        st[a[i].s].insert(a[i].f.s);
    }

    cout << ans << endl;
}