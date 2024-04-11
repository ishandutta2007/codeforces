#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <climits>
#include <utility>

using namespace std;

typedef long long ll;

const int MAXN = 1111;
const int MAXK = 1111111;

set< pair< ll, int > > rows, cols;
ll dec_row, dec_col;
int n, m, k, p;
ll sr[MAXN], sc[MAXN];
ll getrow[MAXK], getcol[MAXK];

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k >> p;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int cur;
            cin >> cur;
            sr[i] += cur;
            sc[j] += cur;
        }
    }
    for (int i = 0; i < n; ++i) {
        rows.insert(make_pair(sr[i], i));
    }
    for (int j = 0; j < m; ++j) {
        cols.insert(make_pair(sc[j], j));
    }
    ll res = LLONG_MIN;
    for (int it = 0; it < k; ++it) {
        pair< ll, int > cur_p = *(rows.rbegin());
        getrow[it + 1] = getrow[it] + cur_p.first;
        rows.erase(cur_p);
        cur_p.first -= m * p;
        rows.insert(cur_p);
        // cols
        cur_p = *(cols.rbegin());
        getcol[it + 1] = getcol[it] + cur_p.first;
        cols.erase(cur_p);
        cur_p.first -= n * p;
        cols.insert(cur_p);
    }
    for (int tp = 0; tp <= k; ++tp) {
        int crow = tp, ccol = k - tp;
        ll cur = 0LL;
        cur += getrow[crow];
        cur += getcol[ccol] - 1ll * p * crow * ccol;
        res = max(cur, res);
    }
    cout << res << '\n';
    return 0;
}