#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



void solve()
{
    int n, m;
    cin >> n >> m;
    vector<LL> vec(n);
    for (int i = 0; i < n; ++i)
    {
        LL s = 0;
        for (int j = 1; j <= m; ++j)
        {
            LL cur;
            cin >> cur;
            s += cur * j;
        }
        vec[i] = s;
    }
    LL tgt;
    if (vec[0] == vec[1])
        tgt = vec[0];
    else
    {
        if (vec[0] == vec[2])
            tgt = vec[0];
        else
            tgt = vec[1];
    }
    for (int i = 0; i < n; ++i)
    {
        if (vec[i] != tgt)
        {
            LL ans = vec[i] - tgt;
            cout << i + 1 << ' ' << ans << '\n';
        }
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