#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <utility>
#include <tuple>

using namespace std;

const int MAXN = 200500;

pair< int, int > x[MAXN];
int rev_id[MAXN];
int n, m;

int
get_id(int from, int to, int id, int len)
{
    while (from != to) {
        int diff_len = (x[to].first - x[from].first);
        int cnt = len / diff_len;
        len %= diff_len;
        if (cnt & 1) {
            id = from + to - id;
        }
        if (!len) {
            return id;
        }
        if (id == from) {
            int pos = upper_bound(x + from, x + to, make_pair(x[from].first + len, n + 1)) - x - 1;
            len -= (x[pos].first - x[from].first);
            to = id = pos;
        } else {
            int pos = lower_bound(x + from, x + to, make_pair(x[to].first - len, -1)) - x;
            len -= (x[to].first - x[pos].first);
            from = id = pos;
        }
    }
    return from;
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> x[i].first;
        x[i].second = i;
    }
    sort(x, x + n);
    for (int i = 0; i < n; ++i) {
        rev_id[x[i].second] = i;
    }
    for (int i = 0; i < m; ++i) {
        int a, len;
        cin >> a >> len;
        a = rev_id[a - 1];
        int res = -1;
        if (a == 0 || a == n - 1) {
            res = get_id(0, n - 1, a, len);
        } else {
            if (x[n - 1].first <= x[a].first + len) {
                res = get_id(0, n - 1, n - 1, len + x[a].first - x[n - 1].first);
            } else {
                int pos = upper_bound(x + a, x + n, make_pair(x[a].first + len, n + 1)) - x - 1;
                res = get_id(0, pos, pos, len + x[a].first - x[pos].first);
            }
        }
        res = x[res].second + 1;
        cout << res << '\n';
    }
    return 0;
}