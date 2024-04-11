#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    int r1, c1, r2, c2, r3, c3;
    cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3;
    int x, y;
    cin >> x >> y;
    bool can[2][2]{};
    can[r1 & 1][c1 & 1] = true;
    can[r2 & 1][c2 & 1] = true;
    can[r3 & 1][c3 & 1] = true;
    if (!can[x & 1][y & 1])
    {
        cout << "NO\n";
        return;
    }
    auto check = [&](int x, int y)
    {
        return x == 1 || x == n || y == 1 || y == n;
    };
    if (check(r1, c1) && check(r2, c2) && check(r3, c3))
    {
        int tr = (r1 == x) + (r2 == x) + (r3 == x);
        int tc = (c1 == y) + (c2 == y) + (c3 == y);
        if (tr >= 2 || tc >= 2)
            cout << "YES\n";
        else
            cout << "NO\n";
        return;
    }
    cout << "YES\n";
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