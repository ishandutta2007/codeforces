#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        a[i] = s[i - 1] - '0';
        a[i] += a[i - 1];
        a[i] %= 9;
    }
    array<array<int, 3>, 9> p{};
    for (int i = 0; i < 9; ++i)
    {
        p[i][0] = i;
    }
    int w, m;
    cin >> w >> m;
    for (int i = 1; i <= n - w + 1; ++i)
    {
        int k = (a[i + w - 1] - a[i - 1] + 9) % 9;
        auto &cur = p[k];
        auto it = find(cur.begin() + 1, cur.end(), 0);
        if (it != cur.end())
        {
            *it = i;
        }
    }
    sort(p.begin(), p.end(), [](auto &x, auto &y){ return x[1] < y[1]; });
    while (m--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        int t = (a[r] - a[l - 1] + 9) % 9;
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (p[i][1] && (p[i][0] * t + p[j][0] - k + 90) % 9 == 0)
                {
                    if (i == j)
                    {
                        if (p[i][2])
                        {
                            cout << p[i][1] << ' ' << p[i][2] << '\n';
                            goto end;
                        }
                        else
                            continue;
                    }
                    if (!p[j][1])
                        continue;
                    cout << p[i][1] << ' ' << p[j][1] << '\n';
                    goto end;
                }
            }
        }
        cout << "-1 -1\n";
        end:;
    }
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