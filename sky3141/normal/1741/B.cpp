#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    if (n == 2)
    {
        cout << "2 1\n";
        return;
    }
    if (n == 3)
    {
        cout << "-1\n";
        return;
    }
    for (int i = 3; i <= n; ++i)
    {
        cout << i << ' ';
    }
    cout << "2 1\n";
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