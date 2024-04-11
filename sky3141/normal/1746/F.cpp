#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9, Tests = 60;

mt19937 gen(random_device{}());
uniform_int_distribution distrib(0, 1);

inline int lowbit(int x)
{
    return x & -x;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> type(q), l(q), r(q), k(q);
    vector<int> values;
    values.reserve(n + q);
    for (auto &x : a)
    {
        cin >> x;
        values.push_back(x);
    }
    for (int i = 0; i < q; ++i)
    {
        cin >> type[i] >> l[i] >> r[i];
        --l[i];
        if (type[i] == 2)
            cin >> k[i];
        if (type[i] == 1)
        {
            values.push_back(r[i]);
        }
    }
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    for (int i = 0; i < n; ++i)
    {
        a[i] = lower_bound(values.begin(), values.end(), a[i]) - values.begin();
    }
    for (int i = 0; i < q; ++i)
    {
        if (type[i] == 1)
        {
            r[i] = lower_bound(values.begin(), values.end(), r[i]) - values.begin();
        }
    }
    vector<bool> ans(q, true);
    vector<int> f(n + 1);
    vector<int> val(n + q);
    vector<int> b(n);
    auto add = [&](int pos, int val)
    {
        for (int i = pos + 1; i <= n; i += lowbit(i))
            f[i - 1] += val;
    };
    auto query = [&](int pos)
    {
        int res = 0;
        for (int i = pos; i; i -= lowbit(i))
            res += f[i - 1];
        return res;
    };
    for (int t_ = 0; t_ < Tests; ++t_)
    {
        fill(f.begin(), f.end(), 0);
        for (int i = 0; i < n + q; ++i)
        {
            val[i] = distrib(gen);
        }
        for (int i = 0; i < n; ++i)
        {
            b[i] = a[i];
            add(i, val[b[i]]);
        }
        for (int i = 0; i < q; ++i)
        {
            if (type[i] == 1)
            {
                add(l[i], val[r[i]] - val[b[l[i]]]);
                b[l[i]] = r[i];
            }
            else
            {
                if ((query(r[i]) - query(l[i])) % k[i] != 0)
                    ans[i] = false;
            }
        }
    }
    for (int i = 0; i < q; ++i)
    {
        if (type[i] == 2)
            cout << (ans[i] ? "YES\n" : "NO\n");
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
}