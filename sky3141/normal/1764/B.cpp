#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int d = 0, mx = 0;
    for (auto &x : a)
    {
        cin >> x;
        mx = max(mx, x);
        d = __gcd(d, x);
    }
    cout << mx / d << '\n';
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