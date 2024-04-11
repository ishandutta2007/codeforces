#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

using LL = long long;

constexpr int MAXN = 50 + 9;
constexpr int path[8][2]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int n, m;
char a[MAXN][MAXN];
int cnt = 0;
int maxr, minr, maxc, minc;

void dfs(int r, int c)
{
    ++cnt;
    maxr = max(maxr, r);
    minr = min(minr, r);
    maxc = max(maxc, c);
    minc = min(minc, c);
    a[r][c] = '.';
    for (auto [dr, dc] : path)
    {
        int nr = r + dr, nc = c + dc;
        if (a[nr][nc] == '*')
        {
            dfs(nr, nc);
        }
    }
}

void solve()
{
    memset(a, 0, sizeof(a));
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == '*')
            {
                cnt = 0;
                maxr = maxc = -100;
                minr = minc = 100;
                dfs(i, j);
                if (cnt != 3 || maxr - minr != 1 || maxc - minc != 1)
                {
                    cout << "no\n";
                    return;
                }
            }
        }
    }
    cout << "yes\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    
    return 0;
}