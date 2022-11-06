#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;

int n, m;

void solve()
{
    cin >> n >> m;
    string a, b;
    cin >> a;
    cin >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    bool can0 = false, can1 = false;
    for (int i = m - 1; i < n; ++i)
    {
        if (a[i] == '0')
            can0 = true;
        else
            can1 = true;
    }
    for (int i = 0; i < m - 1; ++i)
    {
        if (a[i] != b[i])
        {
            cout << "No\n";
            return;
        }
    }
    if ((b.back() == '0' && can0) || (b.back() == '1' && can1))
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}