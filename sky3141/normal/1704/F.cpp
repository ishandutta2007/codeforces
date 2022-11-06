#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

using LL = long long;

// constexpr int MAXN = 500000 + 9;

int sg[1009];
bool vis[1009];

int getsg(int x)
{
    if (x < 1000)
        return sg[x];
    return sg[680 + x % 34];
}

void solve()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    int cnt = 0;
    for (char c : s)
    {
        if (c == 'R')
            ++cnt;
        else
            --cnt;
    }
    if (cnt > 0)
    {
        cout << "Alice\n";
        return;
    }
    if (cnt < 0)
    {
        cout << "Bob\n";
        return;
    }
    int sgsum = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i == 0 || s[i] == s[i - 1])
        {
            int j = i;
            while (j < n - 1 && s[j] != s[j + 1])
                ++j;
            sgsum ^= getsg(j - i + 1);
        }
    }
    if (sgsum != 0)
    {
        cout << "Alice\n";
    }
    else
    {
        cout << "Bob\n";
    }
}

void init()
{
    for (int i = 2; i <= 1000; ++i)
    {
        fill(vis, vis + i + 1, false);
        for (int j = 0; j <= i - 2; ++j)
        {
            vis[sg[j] ^ sg[i - j - 2]] = true;
        }
        int t = 0;
        while (vis[t])
            ++t;
        sg[i] = t;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    init();
    while (T--)
    {
        solve();
    }

    return 0;
}