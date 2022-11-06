#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    int s = 0;
    int ans = n;
    for (auto x : a)
    {
        s += x;
        int cnt = 0;
        int c = 0;
        int t = 0;
        int mx = 0;
        for (auto x : a)
        {
            c += x;
            ++t;
            if (c == s)
            {
                mx = max(mx, t);
                c = 0;
                t = 0;
            }
            else if (c > s)
            {
                goto conti;
            }
        }
        if (t == 0)
            ans = min(ans, mx);
        conti:;
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