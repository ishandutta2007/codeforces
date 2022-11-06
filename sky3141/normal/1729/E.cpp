#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;

LL query(LL a, LL b)
{
    cout << "? " << a << ' ' << b << endl;
    LL res;
    cin >> res;
    return res;
}

void solve()
{
    for (LL i = 1; i <= 50; i += 1)
    {
        LL a = query(i, i + 1);
        LL b = query(i + 1, i);
        if (a == -1)
        {
            cout << i << endl;
            return;
        }
        if (a != b)
        {
            cout << "! " << a + b << endl;
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
}