#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops") 
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int tree[MAXN * 4];
int mod[MAXN * 4];

int get_val(int v)
{
    return tree[v] + mod[v];
}

void push(int v)
{
    mod[v * 2] += mod[v];
    mod[v * 2 + 1] += mod[v];
    mod[v] = 0;
}

int get(int v, int tl, int tr, int l, int r)
{
    if (tl >= r || tr <= l)
        return 1e9;
    if (tl >= l && tr <= r)
    {
        return get_val(v);
    }
    int tm = (tl + tr) / 2;
    push(v);
    int ans = min(get(v * 2, tl, tm, l, r), get(v * 2 + 1, tm, tr, l, r));
    tree[v] = min(get_val(v * 2), get_val(v * 2 + 1));
    return ans;
}

void update(int v, int tl, int tr, int l, int r, int val)
{
    if (tl >= r || tr <= l)
        return;
    if (tl >= l && tr <= r)
    {
        mod[v] += val;
        return;
    }
    int tm = (tl + tr) / 2;
    push(v);
    update(v * 2, tl, tm, l, r, val);
    update(v * 2 + 1, tm, tr, l, r, val);
    tree[v] = min(get_val(v * 2), get_val(v * 2 + 1));
    return;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        x--;
        update(1, 0, n, x, x + 1, 1);
        if (get(1, 0, n, 0, n) >= 1)
        {
            update(1, 0, n, 0, n, -1);
            cout << 1;
        }
        else
            cout << 0;
    }
    return 0;
}