#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

typedef tree<
        int,
        null_type,
        less<>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        Tree ;


typedef long long ll;
const int N = (int)2e5 + 50;

struct qry {
    int pos, idx;
};

int n;
int a[N];
int ids[N];
vector<qry> qr[N];
int res[N];
Tree S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ids[i] = i;
    }
    sort(ids, ids + n, [](const int i, const int j) {
        return (a[i] != a[j] ? a[i] > a[j] : i < j);
    });
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int k, pos; cin >> k >> pos;
        pos--;
        qr[k].push_back({pos, i});
    }
    for(int i = 1; i <= n; i++) {
        S.insert(ids[i-1]);
        for(auto qi : qr[i]) {
            res[qi.idx] = a[*S.find_by_order(qi.pos)];
        }
    }
    for(int i = 0; i < q; i++) cout << res[i] << "\n";



}