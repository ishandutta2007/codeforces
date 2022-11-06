#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    int n, q;
    cin >> n >> q;
    LL s[2]{};
    LL c[2]{};
    for (int i = 0; i < n; ++i)
    {
        LL x;
        cin >> x;
        s[x & 1] += x;
        ++c[x & 1];
    }
    while (q--)
    {
        int type;
        LL x;
        cin >> type >> x;
        if (x & 1)
        {
            s[type] += x * c[type];
            s[type ^ 1] += s[type];
            c[type ^ 1] += c[type];
            s[type] = c[type] = 0;
        }
        else
        {
            s[type] += x * c[type];
        }
        cout << s[0] + s[1] << '\n';
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