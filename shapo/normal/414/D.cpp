#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

#define maxn 100500
#define maxk 500000

ll sum[maxk];
ll add[maxk];
int m, k, p, curk;
int lvl[maxn];
vector< vector< int > > g;
bool used[maxn];

void
dfs(int v, int h)
{
    used[v] = true;
    lvl[v] = h;
    int cnt = int(g[v].size());
    for (int i = 0; i < cnt; ++i) {
        int to = g[v][i];
        if (!used[to]) {
            dfs(to, h + 1);
        }
    }
}

void
push_add(int v)
{
    if (v < curk) {
        add[v * 2] += add[v];
        add[v * 2 + 1] += add[v];
    }
}

ll
getSum(int v, int len)
{
    return (sum[v] + add[v] * len);
}

void
upd(int v, int len)
{
    if (v < curk) {
        sum[v] = getSum(v * 2, len) + getSum(v * 2 + 1, len);
    }
    add[v] = 0LL;
}

void
add1(int from, int to, int l, int r, int v)
{
    if (max(from, l) <= min(r, to)) {
        if (from <= l && to >= r) {
            add[v]++;
            return;
        }
        push_add(v);
        add1(from, to, l, (l + r) / 2, v * 2);
        add1(from, to, (l + r) / 2 + 1, r, v * 2 + 1);
        upd(v, (r - l + 1) / 2);
    }
}

int
getSum(ll exp_sum)
{
    int cur_v = 1;
    int cur_pos = 1;
    int len = curk / 2;
    while (len > 1) {
        push_add(cur_v);
        upd(cur_v, len);
        if (getSum(cur_v * 2 + 1, len) < exp_sum) {
            exp_sum -= getSum(cur_v * 2 + 1, len);
            cur_v = cur_v * 2;
        } else {
            cur_pos += len;
            cur_v = cur_v * 2 + 1;
        }
        len /= 2;
    }
    if (getSum(cur_v, 1) > exp_sum) {
        cur_pos++;
    }
    return cur_pos;
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> m >> k >> p;
    g.resize(m + 5);
    for (int i = 1; i <= m; ++i) {
        used[i] = false;
    }
    for (int i = 0; i < m - 1; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
    sort(lvl + 1, lvl + m + 1);
    curk = 2;
    while (curk <= m) {
        curk *= 2;
    }
    int l = 2;
    int res = 0;
    while (l <= m) {
        int r = l + 1;
        while (r <= m && lvl[r] == lvl[l]) ++r;
        int exp_pos = getSum(p);
        res = max(res, min(r - exp_pos - 1, k));
        add1(1, r - 1, 1, curk, 1);
        l = r;
    }
    cout << res << endl;
    return 0;
}