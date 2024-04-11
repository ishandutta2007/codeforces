#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 10000000;

int n;

struct Item
{
    int t, d, p;
    int id;
} it[102];


bool cmp(Item A, Item B)
{
    return A.d < B.d;
}

int dp[102][2002];
int pr[102][2002];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> it[i].t >> it[i].d >> it[i].p;
        it[i].id = i;
    }

    sort(it + 1, it + 1 + n, cmp);

    for (int i = 1; i <= n; i ++)
    {
        for (int t = 0; t <= 2000; t ++)
        {
            if ( t < it[i].d && t >= it[i].t) 
            {
                dp[i][t] = dp[i-1][t-it[i].t] + it[i].p;
                pr[i][t] = i;  
            }

            if (dp[i-1][t] > dp[i][t])
            {
                dp[i][t] = dp[i-1][t];
                pr[i][t] = pr[i-1][t];
            }

        }
    }

    int ans = 0, pos = -1;
    for (int i = 1; i <= 2000; i ++)
    {
        if (dp[n][i] > ans)
        {
            pos = i; ans = dp[n][i];
        }
    }

    int cur = n;
    vector<int> v;

    while (cur > 0)
    {
        int nxt = pos - it[ pr[cur][pos] ].t;
        if (pr[cur][pos] == 0) break;
        v.push_back(it[ pr[cur][pos] ].id);
        cur = pr[cur][pos] - 1;
        pos = nxt;
    }

    printf("%d\n", ans);
    printf("%d\n", (int)v.size());

    for (int i = (int)v.size() - 1; i >= 0; i --)
    {
        printf("%d ", v[i]);
    }

}