#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
vector <int> edge[MAXN];
int dp[MAXN][3]; // 0: need, 1: good, 2: give

void flood (int cloc, int last)
{
    int mbest = 1e9;
    for (int i = 0; i < edge[cloc].size(); i++)
    {
        int neigh = edge[cloc][i];
        if (neigh == last) continue;
        flood (neigh, cloc);
        dp[cloc][0] += dp[neigh][1];
        dp[cloc][1] += dp[neigh][1];
        mbest = min (mbest, dp[neigh][2] - dp[neigh][1]);
        dp[cloc][2] += dp[neigh][0];
    }
    dp[cloc][1] += mbest;

    if (cloc != 0 && last != 0)
        dp[cloc][2]++;
    dp[cloc][1] = min (dp[cloc][1], dp[cloc][2]);
    dp[cloc][0] = min (dp[cloc][0], dp[cloc][1]);
}

int main()
{
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    flood (0, -1);
    cout << dp[0][2] << "\n";
}