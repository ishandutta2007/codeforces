#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

int n, m;

vector < pair < long long, long long > > g[200000];
set < pair < long long, long long > > S;

long long d[200000], p[200000];

vector < int > ans;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i ++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a].push_back(make_pair((long long)b, (long long)c));
        g[b].push_back(make_pair((long long)a, (long long)c));
    }

    for (int i = 1; i <= n; i ++)
        d[i] = 1000000000000000LL;

    d[1] = 0;
    S.insert(make_pair(d[1], 1));
    while (!S.empty())
    {
        int v = S.begin()->second; S.erase(S.begin());

        for (int i = 0; i < g[v].size(); i ++)
        {
            long long u = g[v][i].first, l = g[v][i].second;
            if (d[u] > d[v] + l)
            {
                S.erase(make_pair(d[u], u));
                d[u] = d[v] + l, p[u] = v;
                S.insert(make_pair(d[u], u));
            }
        }
    }

    if (d[n] == 1000000000000000LL) 
        printf("-1\n"); else
    {
        int v = n;
        while (v != 1)
            ans.push_back(v), v = p[v];
        ans.push_back(1);

        for (int i = ans.size() - 1; i >= 0; i --)
            printf("%d ", ans[i]);
        printf("\n");
    }

    return 0;
}