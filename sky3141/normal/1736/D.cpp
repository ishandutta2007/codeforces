#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < 2 * n; i += 2)
    {
        if (s[i] != s[i + 1])
            ++cnt;
    }
    if (cnt & 1)
    {
        cout << "-1\n";
        return;
    }
    int cur = 0;
    cout << cnt << ' ';
    for (int i = 0; i < 2 * n; i += 2)
    {
        if (s[i] != s[i + 1])
        {
            cout << (s[i] - '0' == cur ? i + 1 : i + 2) << ' ';
            cur ^= 1;
        }
    }
    cout << '\n';
    for (int i = 0; i < 2 * n; i += 2)
    {
        cout << i + 1 << ' ';
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