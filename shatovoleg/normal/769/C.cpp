#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;
using pii = pair<int, int>;

pii d[] = {
    {1, 0},
    {0, -1},
    {0, 1},
    {-1, 0}
};
string moves = "DLRU";

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> fld(n + 2, vector<char>(m + 2, '*'));
    queue<pii> deq;
    pii start;
    vector<vector<int>> dist(n + 2, vector<int>(m + 2, 1000000000));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> fld[i][j];
            if (fld[i][j] == 'X')
            {
                start = {i, j};
                dist[i][j] = 0;
                deq.push({i, j});
                fld[i][j] = '.';
            }
        }
    while (deq.size())
    {
        for (int i = 0; i < 4; ++i)
            if (fld[deq.front().first + d[i].first][deq.front().second + d[i].second] == '.' &&
                dist[deq.front().first + d[i].first][deq.front().second + d[i].second] >
                dist[deq.front().first][deq.front().second] + 1)
            {
                deq.push({deq.front().first + d[i].first, deq.front().second + d[i].second});
                dist[deq.front().first + d[i].first][deq.front().second + d[i].second] = dist[deq.front().first][deq.front().second] + 1;
            }
        deq.pop();
    }
    string res = "";
    int left = k;
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < 4; ++j)
            if (dist[start.first + d[j].first][start.second + d[j].second] < left)
            {
                res += moves[j];
                start.first += d[j].first;
                start.second += d[j].second;
                --left;
                break;
            }
    }
    if (res.length() != k)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << res << endl;
}