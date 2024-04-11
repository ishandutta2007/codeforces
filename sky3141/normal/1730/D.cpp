#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int cnt[26][26]{};
    for (int i = 0; i < n; ++i)
    {
        int a = s1[i] - 'a', b = s2[n - 1 - i] - 'a';
        if (a > b)
            swap(a, b);
        ++cnt[a][b];
    }
    int t = 0;
    for (int i = 0; i < 26; ++i)
    {
        for (int j = i; j < 26; ++j)
        {
            t += cnt[i][j] & (~1);
            cnt[i][j] &= 1;
        }
    }
    if (n & 1)
    {
        for (int i = 0; i < 26; ++i)
        {
            if (cnt[i][i])
            {
                ++t;
                break;
            }
        }
    }
    cout << (t == n ? "YES\n" : "NO\n");
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