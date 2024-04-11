#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;

struct GoTime
{
    int next[60];
};

const int MAXN = 100500;
const int MAXK = 131072;

GoTime tree[2 * MAXK];
int curk;
int n;
vector< int > per;

void
calc_times(const GoTime &from, const GoTime &to, GoTime &res)
{
    for (int i = 0; i < 60; ++i) {
        int len = from.next[i];
        res.next[i] = to.next[(i + len) % 60] + len;
    }
}

void
upd_val(int x, int per)
{
    x += curk - 1;
    for (int i = 0; i < 60; ++i) {
        tree[x].next[i] = 1;
    }
    for (int i = 0; i < 60; i += per) {
        tree[x].next[i]++;
    }
    int par = x / 2;
    while (par) {
        calc_times(tree[par * 2], tree[par * 2 + 1], tree[par]);
        par /= 2;
    }
}

int
get_ans(int from, int to)
{
    vector< int > st, rev;
    from += curk - 1;
    to += curk - 1;
    while (from < to) {
        if (from % 2 == 1) {
            st.push_back(from);
        }
        if (to % 2 == 0) {
            rev.push_back(to);
        }
        from = (from + 1) / 2;
        to = (to - 1) / 2;
    }
    if (from == to) {
        st.push_back(from);
    }
    st.insert(st.end(), rev.rbegin(), rev.rend());
    int len = 0;
    int ct = 0;
    for (auto v : st) {
        int cur_len = tree[v].next[ct];
        len += cur_len;
        ct = (ct + cur_len) % 60;
    }
    return len;
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    per.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> per[i];
    }
    curk = 2;
    while (curk < n) {
        curk *= 2;
    }
    for (int i = curk; i < 2 * curk; ++i) {
        fill(tree[i].next, tree[i].next + 60, 1);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 60; j += per[i]) {
            tree[i + curk - 1].next[j]++;
        }
    }
    for (int i = curk - 1; i >= 1; --i) {
        calc_times(tree[i * 2], tree[i * 2 + 1], tree[i]);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == 'C') {
            upd_val(a, b);
        } else {
            int res = get_ans(a, b - 1);
            cout << res << '\n';
        }
    }
    return 0;
}