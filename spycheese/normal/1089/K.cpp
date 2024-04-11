#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const ll inf = 1e18 + 7;

const int N = 3e5 + 7;

ll max_d[4 * N];
ll add_d[4 * N];
ll t[4 * N];

void upd(int v, ll a, ll b)
{
    t[v] = max(t[v], a) + b;
    max_d[v] = max(max_d[v], a - add_d[v]);
    add_d[v] += b;
}

void push(int v)
{
    upd(v * 2 + 1, max_d[v], add_d[v]);
    upd(v * 2 + 2, max_d[v], add_d[v]);
    max_d[v] = -inf;
    add_d[v] = 0;
}

void upd(int v, int l, int r, int tl, int tr, ll x, ll y)
{
    if (tl >= r || tr <= l)
    {
        return;
    }
    if (tl >= l && tr <= r)
    {
        upd(v, x, y);
    }
    else
    {
        int tm = (tl + tr) / 2;
        push(v);
        upd(v * 2 + 1, l, r, tl, tm, x, y);
        upd(v * 2 + 2, l, r, tm, tr, x, y);
        t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
    }
}

ll get(int v, int l, int r, int tl, int tr)
{
    if (tl >= r || tr <= l)
    {
        return -inf;
    }
    if (tl >= l && tr <= r)
    {
        return t[v];
    }
    else
    {
        int tm = (tl + tr) / 2;
        push(v);
        return max(get(v * 2 + 1, l, r, tl, tm), get(v * 2 + 2, l, r, tm, tr));
    }
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 4 * N; i++)
    {
        max_d[i] = -1e18;
    }
    int q;
    cin >> q;
    vector <int> l(q), r(q);
    vector <int> d(q);
    vector <pair <int, int> > ans;
    vector <pair <int, int> > quer;
    for (int i = 0; i < q; i++)
    {
        char c;
        cin >> c;
        if (c == '+')
        {
            int t;
            cin >> t >> d[i];
            ans.push_back({t, i});
            l[i] = i;
            r[i] = q;
        }
        else if (c == '-')
        {
            int j;
            cin >> j;
            j--;
            r[j] = i;
        }
        else
        {
            int t;
            cin >> t;
            quer.push_back({t, i});
        }
    }
    sort(ans.begin(), ans.end());
    sort(quer.begin(), quer.end());
    vector <ll> ret(q, -1);
    int j = -1;
    for (int i = 0; i < (int) quer.size(); i++)
    {
        while (j + 1 < (int) ans.size() && ans[j + 1].first <= quer[i].first)
        {
            j++;
            int ind = ans[j].second;
            upd(0, l[ind], r[ind], 0, q, ans[j].first, d[ind]);
        }
        ret[quer[i].second] = max(0ll, get(0, quer[i].second, quer[i].second + 1, 0, q) - quer[i].first);
    }
    for (int i = 0; i < q; i++)
    {
        if (ret[i] != -1)
            cout << ret[i] << '\n';
    }
}