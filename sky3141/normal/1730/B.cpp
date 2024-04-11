#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    for (auto &x : b)
    {
        cin >> x;
    }
    int mn = 1000000000, mx = 0;
    for (int i = 0; i < n; ++i)
    {
        int c = a[i] + b[i], d = a[i] - b[i];
        mn = min({mn, c, d});
        mx = max({mx, c, d});
    }
    int t = mx + mn;
    cout << t / 2;
    if (t & 1)
        cout << ".5";
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