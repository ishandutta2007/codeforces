#include <iostream>
#include <algorithm>

using namespace std;

constexpr int MAXNM = 100000 + 9;

int cnt[MAXNM];

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            ++cnt[max(i, n - 1 - i) + max(j, m - 1 - j)];
        }
    }
    int cur = 0;
    for (int i = 0; i < n * m; ++i)
    {
        while (cnt[cur] == 0)
        {
            ++cur;
        }
        cout << cur << ' ';
        --cnt[cur];
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