#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



void solve()
{
    int n, d12, d23, d13;
    cin >> n >> d12 >> d23 >> d13;
    if ((d12 + d23 + d13) % 2 != 0)
    {
        cout << "NO\n";
        return;
    }
    int sn = (d12 + d23 + d13) / 2 + 1;
    if (sn > n)
    {
        cout << "NO\n";
        return;
    }
    int t = (d12 + d13 - d23) / 2;
    if (t < 0 || t > d12 || t > d13)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    if (d13 + d23 == d12)
    {
        vector<int> a(d12 + 1, 0);
        a[0] = 1;
        a[d12] = 2;
        a[t] = 3;
        int nxt = 4;
        for (auto &x : a)
        {
            if (x == 0)
                x = nxt++;
        }
        for (int i = 1; i <= d12; ++i)
        {
            cout << a[i - 1] << ' ' << a[i] << '\n';
        }
        while (nxt <= n)
        {
            cout << nxt - 1 << ' ' << nxt << '\n';
            ++nxt;
        }
        return;
    }
    int nxt = 4;
    vector<int> a;
    a.reserve(d12 + 1);
    a.push_back(1);
    for (int i = 1; i < d12; ++i)
    {
        a.push_back(nxt++);
    }
    a.push_back(2);
    for (int i = 1; i < a.size(); ++i)
    {
        cout << a[i - 1] << ' ' << a[i] << '\n';
    }
    vector<int> b;
    b.reserve(d13 - t + 1);
    b.push_back(a[t]);
    for (int i = 1; i < d13 - t; ++i)
    {
        b.push_back(nxt++);
    }
    b.push_back(3);
    for (int i = 1; i < b.size(); ++i)
    {
        cout << b[i - 1] << ' ' << b[i] << '\n';
    }
    while (nxt <= n)
    {
        cout << nxt - 1 << ' ' << nxt << '\n';
        ++nxt;
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