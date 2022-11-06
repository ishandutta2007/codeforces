#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;

int sz(const string &s)
{
    int res;
    if (s.back() == 'S')
    {
        res = -1;
    }
    else if (s.back() == 'M')
        return 0;
    else
    {
        res = 1;
    }
    res *= count(s.begin(), s.end(), 'X') + 1;
    return res;
}

void solve()
{
    string a, b;
    cin >> a >> b;
    int sa = sz(a), sb = sz(b);
    if (sa < sb)
    {
        cout << "<\n";
    }
    else if (sa == sb)
    {
        cout << "=\n";
    }
    else
        cout << ">\n";
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