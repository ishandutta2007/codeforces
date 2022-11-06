#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

using LL = long long;

constexpr int MAXN = 500 + 9;

int n, m;
char a[MAXN][MAXN];

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int count1 = 0;
    int loss = 2;
    for (int i = 0; i < n; ++i)
    {
        int tc = count(a[i], a[i] + m, '1');
        count1 += tc;
        if (tc < m)
            loss = 1;
    }
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < m - 1; ++j)
        {
            int cnt = 0;
            for (int x = i; x <= i + 1; ++x)
            {
                for (int y = j; y <= j + 1; ++y)
                {
                    if (a[x][y] == '0')
                        ++cnt;
                }
            }
            if (cnt >= 2)
                loss = 0;
        }
    }
    cout << count1 - loss << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}