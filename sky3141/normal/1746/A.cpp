#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    bool f = find(a.begin(), a.end(), 1) != a.end();
    cout << (f ? "YES\n" : "NO\n");
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