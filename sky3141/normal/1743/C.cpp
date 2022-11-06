#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    vector<array<int, 2>> f(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        // f[i] = f[i - 1];
        if (s[i] == '1')
        {
            f[i][1] = max(f[i - 1][1], f[i - 1][0]) + a[i];
            f[i][0] = max({f[i - 1][0], f[i - 1][0] + a[i - 1]});
        }
        else
        {
            f[i][0] = max(f[i - 1][1], f[i - 1][0]);
            f[i][1] = 0;
        }
    }
    cout << max(f[n][0], f[n][1]) << '\n';
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