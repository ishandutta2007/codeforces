#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), d(n);
    for (auto &x : d)
    {
        cin >> x;
    }
    a[0] = d[0];
    for (int i = 1; i < n; ++i)
    {
        if (d[i] != 0 && a[i - 1] >= d[i])
        {
            cout << "-1\n";
            return;
        }
        a[i] = a[i - 1] + d[i];
    }
    for (auto &x : a)
    {
        cout << x << ' ';
    }
    cout << '\n';
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