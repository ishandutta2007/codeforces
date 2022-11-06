#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    vector<int> xsum(n);
    int ttt = 0;
    for (int i = 0; i < n; ++i)
    {
        ttt ^= a[i];
        xsum[i] = ttt;
    }
    vector<int> nxt[30], pre[30];
    for (auto &v : nxt)
    {
        v = vector<int>(n);
    }
    for (auto &v : pre)
    {
        v = vector<int>(n);
    }
    for (int t = 0; t < 30; ++t)
    {
        int lst = -1;
        for (int i = 0; i < n; ++i)
        {
            pre[t][i] = lst;
            if (a[i] & (1 << t))
                lst = i;
        }
        lst = n;
        for (int i = n - 1; i >= 0; --i)
        {
            nxt[t][i] = lst;
            if (a[i] & (1 << t))
                lst = i;
        }
    }
    vector<pair<int, int>> qry(q);
    for (auto &[l, r] : qry)
    {
        cin >> l >> r;
        --l; --r;
        vector<array<int, 4>> f;
        int t = xsum[r] ^ (l == 0 ? 0 : xsum[l - 1]);
        for (int i = 0; i < 30; ++i)
        {
            int tl = a[l] & (1 << i) ? l : nxt[i][l];
            int tr = a[r] & (1 << i) ? r : pre[i][r];
            if (tl >= tr)
                continue;
            if (t & (1 << i))
            {
                f.push_back({tl, nxt[i][tl], pre[i][tr], tr});
            }
            else
            {
                f.push_back({tl, tl, tr, tr});
            }
        }
        sort(f.begin(), f.end(), [](auto &x, auto &y){ return x[0] < y[0]; });
        int mxl = n, mxr = 0;
        for (auto &t : f)
        {
            mxl = min(mxl, t[1]);
            mxr = max(mxr, t[2]);
        }
        int ansl = l, ansr = r;
        // if (!f.empty())
        // {
        //     ansl = f[0][0];
        //     ansr = mxr;
        // }
        for (auto &[l1, l2, r1, r2] : f)
        {
            int tl = min(mxl, l1), tr = mxr;
            if (tr - tl < ansr - ansl)
            {
                ansl = tl;
                ansr = tr;
            }
            mxr = max(mxr, r2);
        }
        if (!f.empty())
        {
            int tl = mxl, tr = mxr;
            if (tr - tl < ansr - ansl)
            {
                ansl = tl;
                ansr = tr;
            }
        }
        else
        {
            ansl = ansr = l;
        }
        cout << ansl + 1 << ' ' << ansr + 1 << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}