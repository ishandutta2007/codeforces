#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

using LL = long long;

constexpr int MAXK = 100 + 9;

LL f[200];
int k;
bool can[200];
// int c[MAXK];
// int m[MAXK];
int cnt[200];

void solve()
{
    f[0] = f[1] = 1;
    for (int i = 2; i < 60; ++i)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    fill(cnt, cnt + 60, 0);
    fill(can, can + 60, false);
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        int c;
        cin >> c;
        int m = 43;
        for (int j = 43; j >= 0; --j)
        {
            if (j <= m && c >= f[j])
            {
                if (j % 2 == 1 && c == f[j])
                    can[j] = true;
                ++cnt[j];
                c -= f[j];
                m = j - 2;
            }
        }
        if (c)
        {
            cout << "Error\n";
            while (true)
                ;
            // return;
        }
    }
    if (cnt[0] == 0)
    {
        for (int i = 49; i > 0; i -= 2)
        {
            if (can[i] && cnt[i] && !cnt[i - 1])
            {
                for (int j = 0; j < i; j += 2)
                    ++cnt[j];
                --cnt[i];
                break;
            }
        }
    }
    int t = 0;
    for (t = 55; t >= 0 && cnt[t] == 0; --t)
        ;
    for (int i = 0; i <= t; ++i)
    {
        if (cnt[i] != 1)
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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