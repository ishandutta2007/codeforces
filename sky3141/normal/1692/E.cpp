#include <bits/stdc++.h>

using namespace std;

using LL = long long;



void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    int t = (int)count(a.begin(), a.end(), 1) - k;
    if (t < 0)
    {
        cout << "-1\n";
        return;
    }
    vector<int> b(n + 1), c(n + 1);
    int cur = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i])
        {
            ++cur;
            b[cur] = i + 1;
        }
    }
    cur = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i])
        {
            ++cur;
            c[cur] = n - i;
        }
    }
    c[cur] = n;
    int ans = 1000000000;
    for (int i = 0; i <= t; ++i)
    {
        ans = min(ans, b[i] + c[t - i]);
    }
    cout << ans << '\n';
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