#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    int t = 0;
    for (int i = 1; i < n - 1; ++i)
    {
        if (a[i] > a[i - 1] + a[i + 1])
            ++t;
    }
    if (k == 1)
    {
        cout << (n - 1) / 2 << '\n';
    }
    else
    {
        cout << t << '\n';
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