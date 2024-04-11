#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    int m;
    cin >> m;
    vector<int> a(m);
    for (auto &x : a)
    {
        cin >> x;
        --x;
    }
    int ans = 0;
    for (int i = 1; i < m; i *= 2)
    {
        for (int j = 0; j < m; j += i * 2)
        {
            if (!((a[j] ^ a[j + i]) & i))
            {
                cout << "-1\n";
                return;
            }
            for (int k = 1; k < i; ++k)
            {
                if (((a[j + k] ^ a[j]) & i) || ((a[j + i + k] ^ a[j + i]) & i))
                {
                    cout << "-1\n";
                    return;
                }
            }
            if (a[j] & i)
                ++ans;
        }
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