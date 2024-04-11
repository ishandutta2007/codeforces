#include <iostream>

using namespace std;

constexpr int MAXN = 50 + 9;

char map[MAXN][MAXN];

void solve()
{
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    for (int i = 0; i < n; ++i)
    {
        cin >> map[i];
    }
    --r;
    --c;
    if (map[r][c] == 'B')
    {
        cout << "0\n";
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if (map[i][c] == 'B')
        {
            cout << "1\n";
            return;
        }
    }
    for (int i = 0; i < m; ++i)
    {
        if (map[r][i] == 'B')
        {
            cout << "1\n";
            return;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (map[i][j] == 'B')
            {
                cout << "2\n";
                return;
            }
        }
    }
    cout << "-1\n";
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