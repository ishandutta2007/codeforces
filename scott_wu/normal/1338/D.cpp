#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
vector <int> edge[MAXN];
int dp[MAXN][2];
int ans;

void flood (int cloc, int last)
{
    int deg = edge[cloc].size();

    ans = max (ans, deg);
    vector <int> d1, d2;
    d1.push_back(0);
    d1.push_back(0);
    d2.push_back(0);
    d2.push_back(0);

    //int m1 = -1e9, m2 = -1e9;
    for (int neigh : edge[cloc])
    {
        if (neigh == last) continue;
        flood (neigh, cloc);
        // some stuff

        d1.push_back (dp[neigh][0]);
        d2.push_back (dp[neigh][1]);

        /*if (dp[neigh] > m2)
        {
            m2 = dp[neigh];
            if (m1 < m2) swap (m1, m2);
        }*/
    }

    sort (d1.begin(), d1.end());
    reverse (d1.begin(), d1.end());
    sort (d2.begin(), d2.end());
    reverse (d2.begin(), d2.end());

    // take
    ans = max (ans, 1 + d1[0] + d1[1]);
    // no
    ans = max (ans, max (0, deg - 2) + d2[0] + d2[1]);
    dp[cloc][0] = max (deg - 1, d2[0] + deg - 2);
    dp[cloc][1] = max (d1[0] + 1, dp[cloc][0]);

    /*ans = max (ans, m1 + deg - 1);
    ans = max (ans, m1 + m2 + deg - 2);
    dp[cloc] = max (deg - 1, m1 + deg - 2);*/
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    ans = 0;
    flood (0, -1);
    cout << ans << "\n";
}