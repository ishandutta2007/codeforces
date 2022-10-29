#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

typedef pair< int, int > pii;

vector< int > tree;
vector< int > p, q, res;
int n, curk;
vector< int > valp, valq;

void
upd(int pos, int val)
{
    pos += curk;
    tree[pos] = val;
    while (pos != 1) {
        pos /= 2;
        tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
    }
}

int
sum(int from, int to)
{
    int res = 0;
    from += curk;
    to += curk;
    while (from < to) {
        if (from % 2 == 1) {
            res += tree[from];
        }
        if (to % 2 == 0) {
            res += tree[to];
        }
        from = (from + 1) / 2;
        to = (to - 1) / 2;
    }
    if (from == to) {
        res += tree[from];
    }
    return res;
}

int
get_val(int sum)
{
    int v = 1;
    while (v < curk) {
        if (tree[v * 2] < sum) {
            sum -= tree[v * 2];
            v = v * 2 + 1;
        } else {
            v *= 2;
        }
    }
    return v - curk;
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    curk = 2;
    while (curk < n) {
        curk *= 2;
    }
    p.resize(n), q.resize(n), res.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int j = 0; j < n; ++j) {
        cin >> q[j];
    }
    valp.resize(n), valq.resize(n);
    tree.assign(2 * curk, 0);
    for (int i = 0; i < n; ++i) {
        upd(p[i], 1);
    }
    for (int i = 0, j = n - 1; i < n - 1; ++i, --j) {
        valp[j] = sum(0, p[i] - 1);
        upd(p[i], 0);
    }
    tree.assign(2 * curk, 0);
    for (int i = 0; i < n; ++i) {
        upd(p[i], 1);
    }
    for (int i = 0, j = n - 1; i < n - 1; ++i, --j) {
        valq[j] = sum(0, q[i] - 1);
        upd(q[i], 0);
    }
    int cur_sum = 0;
    for (int i = 0; i < n; ++i) {
        cur_sum = cur_sum + valp[i] + valq[i];
        valp[i] = cur_sum % (i + 1);
        cur_sum /= (i + 1);
    }
    tree.assign(2 * curk, 0);
    for (int i = 0; i < n; ++i) {
        upd(i, 1);
    }
    for (int i = 0, j = n - 1; i < n; ++i, --j) {
        res[i] = get_val(valp[j] + 1);
        upd(res[i], 0);
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " \n"[i == n - 1];
    }
    return 0;
}