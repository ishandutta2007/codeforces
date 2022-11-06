#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 100 + 9;

bool f[MAXN][MAXN][2];

void solve()
{
    int n;
    int odd = 0, even = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (x & 1)
            ++odd;
        else
            ++even;
    }
    for (int i = 0; i <= odd; ++i)
    {
        for (int j = 0; j <= even; ++j)
        {
            if (i == 0 && j == 0)
            {
                f[i][j][0] = true;
                f[i][j][1] = false;
                continue;
            }
            f[i][j][0] = f[i][j][1] = false;
            if (i > 0)
            {
                if (!f[i - 1][j][i & 1])
                {
                    f[i][j][1] = true;
                }
                if (!f[i - 1][j][(i & 1) ^ 1])
                {
                    f[i][j][0] = true;
                }
            }
            if (j > 0)
            {
                if (!f[i][j - 1][i & 1])
                {
                    f[i][j][1] = true;
                }
                if (!f[i][j - 1][(i & 1) ^ 1])
                {
                    f[i][j][0] = true;
                }
            }
        }
    }
    cout << (f[odd][even][0] ? "Alice\n" : "Bob\n");
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