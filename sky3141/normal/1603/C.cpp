#include <iostream>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = 100000 + 9, mod = 998244353;

int n;
int a[MAXN];
int ta[MAXN];
int tb[MAXN];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    LL ans = 0;
    LL sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        ta[i] = a[i];
        tb[i] = 1;
        int p = i - 1;
        while (p >= 1)
        {
            int b = (a[p] + ta[p + 1] - 1) / ta[p + 1];
            if (b == tb[p])
                break;
            sum += (LL)p * (b - tb[p]);
            sum %= mod;
            tb[p] = b;
            ta[p] = a[p] / b;
            --p;
        }
        ans += sum;
        ans %= mod;
    }
    cout << ans << '\n';
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