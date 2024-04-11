#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
        while (x % 10 != 2 && x % 10 != 0)
            x += x % 10;
    }
    if (a[0] % 10 == 0)
    {
        for (int i = 1; i < n; ++i)
        {
            if (a[i] != a[0])
            {
                cout << "No\n";
                return;
            }
        }
        cout << "Yes\n";
        return;
    }
    for (int i = 1; i < n; ++i)
    {
        if ((a[i] - a[0]) % 20 != 0)
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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