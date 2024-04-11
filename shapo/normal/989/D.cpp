#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector< int > vi;

int
main()
{
    ios_base::sync_with_stdio(false);
    int n, l, w_max;
    cin >> n >> l >> w_max;
    vi pos_v, neg_v;
    for (int i = 0; i < n; ++i) {
        int x, v;
        cin >> x >> v;
        (v == -1 ? neg_v : pos_v).push_back(x);
    }
    sort(pos_v.begin(), pos_v.end());
    sort(neg_v.begin(), neg_v.end());
    ll ans = 0ll;
    int pos_sz = int(pos_v.size()), neg_sz = int(neg_v.size());
    for (int pos_ptr = 0, neg_ptr_1 = 0, neg_ptr_2 = 0, neg_ptr_3 = 0; pos_ptr < pos_sz; ++pos_ptr) {
        int x = pos_v[pos_ptr];
        while (neg_ptr_1 < neg_sz && neg_v[neg_ptr_1] <= x) ++neg_ptr_1;
        while (neg_ptr_2 < neg_sz && 1ll * (w_max + 1) * x >= 1ll * (w_max - 1) * (neg_v[neg_ptr_2] + l)) ++neg_ptr_2;
        while (neg_ptr_3 < neg_sz && 1ll * (w_max - 1) * x >= 1ll * (w_max + 1) * (neg_v[neg_ptr_3] + l)) ++neg_ptr_3;
        ans += neg_sz - max(neg_ptr_1, max(neg_ptr_3, neg_ptr_2));
    }
    cout << ans << endl;
    return 0;
}