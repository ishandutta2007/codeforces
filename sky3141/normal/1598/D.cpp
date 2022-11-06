#include <iostream>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;

struct Num
{
    int a, b;
};

int n;
Num num[MAXN];
int cnta[MAXN], cntb[MAXN];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cnta[i] = cntb[i] = 0;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> num[i].a >> num[i].b;
        ++cnta[num[i].a];
        ++cntb[num[i].b];
    }
    LL ans = (LL)n * (n - 1) * (n - 2) / 6;
    for (int i = 0; i < n; ++i)
    {
        ans -= (LL)(cnta[num[i].a] - 1) * (cntb[num[i].b] - 1);
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        solve();
    }

    return 0;
}