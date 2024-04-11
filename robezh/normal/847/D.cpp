#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
typedef pair<int, int> P;
typedef long long ll;
using namespace __gnu_pbds;
const int N = (int)2e5 + 50;

typedef tree<
        P,
        null_type,
        less<>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        my_tree;


int n, T;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    my_tree tree;
    cin >> n >> T;
    int res = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        tree.insert({max(0, a[i] - i), i});
        res = max(res, (int)tree.order_of_key({T - i, -1}));
    }
    cout << res << endl;

}