#include <iostream>
#include <vector>
#include <array>

using namespace std;

constexpr int MAXN = 1000 + 9;

int n, m;
int map[MAXN][MAXN];
vector<array<int, 3>> ans;

bool check(int x, int y)
{
    if (x < 1 || x >= n || y < 1 || y >= m)
        return false;
    int a = map[x][y], b = map[x][y + 1], c = map[x + 1][y], d = map[x + 1][y + 1];
    int tmp[4], cnt = 0;
    if (a)
    {
        tmp[cnt++] = a;
    }
    if (b)
    {
        tmp[cnt++] = b;
    }
    if (c)
    {
        tmp[cnt++] = c;
    }
    if (d)
    {
        tmp[cnt++] = d;
    }
    if (cnt > 0)
    {
        for (int i = 1; i < cnt; ++i)
        {
            if (tmp[i] != tmp[0])
                return false;
        }
    }
    else
    {
        return false;
    }
    return true;
}

inline void clear(int x, int y)
{
    int tmp = max(map[x][y], max(map[x][y + 1], max(map[x + 1][y], map[x + 1][y + 1])));
    if (tmp)
    {
        ans.push_back({x, y, tmp});
    }
    map[x][y] = map[x][y + 1] = map[x + 1][y] = map[x + 1][y + 1] = 0;
}

void dfs(int x, int y)
{
    clear(x, y);
    for (int i = x - 1; i <= x + 1; ++i)
    {
        for (int j = y - 1; j <= y + 1; ++j)
        {
            if (check(i, j))
            {
                dfs(i, j);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            if (check(i, j))
            {
                dfs(i, j);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (map[i][j])
            {
                cout << "-1\n";
                return 0;
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto it = ans.rbegin(); it != ans.rend(); ++it)
    {
        cout << (*it)[0] << ' ' << (*it)[1] << ' ' << (*it)[2] << '\n';
    }

    return 0;
}