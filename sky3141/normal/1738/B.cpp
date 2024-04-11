#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



void solve()
{
    int n, k;
    cin >> n >> k;
    vector<LL> a(n + 1), s(n + 1);
    for (int i = n - k + 1; i <= n; ++i)
    {
        cin >> s[i];
    }
    if (k == 1)
    {
        cout << "Yes\n";
        return;
    }
    for (int i = n - k + 2; i <= n; ++i)
    {
        a[i] = s[i] - s[i - 1];
    }
    bool ans = true;
    for (int i = n - k + 3; i <= n; ++i)
    {
        if (a[i] < a[i - 1])
            ans = false;
    }
    if (a[n - k + 2] * (n - k + 1) < s[n - k + 1])
        ans = false;
    cout << (ans ? "Yes\n" : "No\n");
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