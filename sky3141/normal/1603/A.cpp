#include <iostream>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = 100000 + 9;

int n;
int a[MAXN];

LL gcd(LL a, LL b)
{
    return b == 0 ? a : gcd(b, a % b);
}

inline LL lcm(LL a, LL b)
{
    return a * b / gcd(a, b);
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    LL l = 1;
    for (int i = 1; i <= n; ++i)
    {
        l = lcm(l, i + 1);
        if (a[i] % l == 0)
        {
            cout << "NO\n";
            return;
        }
        if (l > 10000000000)
            break;
    }
    cout << "YES\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}