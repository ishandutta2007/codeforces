#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int d = 0;
    for (auto &x : a)
    {
        cin >> x;
        d = gcd(d, x);
    }
    int ans = 1000000000;
    if (d == 1)
        ans = 0;
    else if (gcd(n, d) == 1)
        ans = 1;
    else if (gcd(n - 1, d) == 1)
        ans = 2;
    else
        ans = 3;
    cout << ans << '\n';
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