#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

using LL = long long;

constexpr int MAXN = 200 + 9, MAXM = 500 + 9;

int n, m;
bool q[MAXM];

int query()
{
    cout << "? ";
    for (int i = 0; i < m; ++i)
    {
        cout << q[i];
    }
    cout << endl;
    int res;
    cin >> res;
    return res;
}

void solve()
{
    cin >> n >> m;
    fill(q, q + m, false);
    vector<pair<int, int>> e(m);
    for (int i = 0; i < m; ++i)
    {
        e[i].first = i;
        q[i] = true;
        e[i].second = query();
        q[i] = false;
    }
    sort(e.begin(), e.end(), [](auto &x, auto &y){ return x.second < y.second; });
    int last = 0;
    int ans = 0;
    for (auto [id, w] : e)
    {
        q[id] = true;
        int cur = query();
        if (cur - last == w)
            ans += w;
        last = cur;
    }
    cout << "! " << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    while (T--)
    {
        solve();
    }

    return 0;
}