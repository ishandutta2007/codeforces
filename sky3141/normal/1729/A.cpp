#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int x = a - 1, y = abs(b - c) + c - 1;
    if (x > y)
    {
        cout << 2;
    }
    else if (x < y)
        cout << 1;
    else
        cout << 3;
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