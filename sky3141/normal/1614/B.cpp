#include <iostream>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;

struct Building
{
    int id;
    int num;
    int pos;
};

int n;
Building a[MAXN];

void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].num;
        a[i].id = i;
    }
    sort(a, a + n, [](const auto &x, const auto &y){ return x.num > y.num; });
    LL ans = 0;
    int ttt = 2;
    for (int i = 0; i < n; ++i)
    {
        int curpos = (ttt >> 1) * (ttt & 1 ? -1 : 1);
        ++ttt;
        a[i].pos = curpos;
        ans += (LL)abs(curpos) * a[i].num;
    }
    ans *= 2;
    sort(a, a + n, [](const auto &x, const auto &y){ return x.id < y.id; });
    cout << ans << '\n';
    cout << "0 ";
    for (int i = 0; i < n; ++i)
    {
        cout << a[i].pos << ' ';
    }
    cout << '\n';
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