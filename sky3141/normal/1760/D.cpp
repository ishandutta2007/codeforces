#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    int s = 0;
    int pre = 1000000000;
    for (auto x : a)
    {
        if (s == 0)
        {
            if (x > pre)
                s = 1;
        }
        else
        {
            if (x < pre)
                s = 2;
        }
        pre = x;
    }
    cout << (s == 2 ? "no" : "yes") << '\n';
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