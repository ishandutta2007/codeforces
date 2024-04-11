#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    int n, k;
    cin >> n >> k;
    int m = n / k;
    string s;
    cin >> s;
    array<int, 26> cnt{};
    for (auto c : s)
    {
        ++cnt[c - 'a'];
    }
    string ans;
    for (int i = 0; i < k; ++i)
    {
        int t = min(m, 25);
        for (int j = 0; j < min(m, 25); ++j)
        {
            if (cnt[j] == 0)
            {
                t = j;
                break;
            }
            --cnt[j];
        }
        ans += 'a' + t;
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