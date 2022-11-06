#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using LL = long long;

constexpr int MAXN = 1000 + 9;

struct Point
{
    int r, c;
};

int n, m;
char s[MAXN];

int calc(const vector<Point> &vec, const Point &cur)
{
    int res = 0;
    for (auto &p : vec)
    {
        res = max(res, abs(p.r - cur.r) + abs(p.c - cur.c));
    }
    return res;
}

void solve()
{
    vector<Point> points;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s;
        for (int j = 1; j <= m; ++j)
        {
            if (s[j - 1] == 'B')
                points.push_back({i, j});
        }
    }
    int step;
    for (step = 1; step <= max(n, m); step <<= 1)
        ;
    Point pos{1, 1};
    while (step)
    {
        int curans = n + m + 100;
        Point best;
        for (int dr = -step; dr <= step; dr += step)
        {
            for (int dc = -step; dc <= step; dc += step)
            {
                Point cur{pos.r + dr, pos.c + dc};
                int tmp = calc(points, cur);
                if (tmp < curans)
                {
                    best = cur;
                    curans = tmp;
                }
            }
        }
        pos = best;
        step >>= 1;
    }
    cout << pos.r << ' ' << pos.c << '\n';
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