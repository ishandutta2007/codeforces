#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;

int n;
int b[N];
bool f[N];

void solve()
{
    cin >> n;
    fill(f, f + n + 1, false);
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
    }
    f[0] = true;
    for (int i = 1; i <= n; ++i)
    {
        if (i - b[i] - 1 >= 0)
            f[i] |= f[i - b[i] - 1];
        if (i + b[i] <= n)
            f[i + b[i]] |= f[i - 1];
    }
    cout << (f[n] ? "YES\n" : "NO\n");
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