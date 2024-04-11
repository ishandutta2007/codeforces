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
    bool t = false;
    int ans = 0;
    for (auto c : s)
    {
        bool cur = c == '1';
        cur ^= t;
        if (cur)
        {
            ++ans;
            t ^= 1;
        }
    }
    ans = max(ans - 1, 0);
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