#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 3;
int forw[MAXN][10];
int amt[MAXN];
int vist[MAXN];
int n, m;

void dfs(int src)
{
    vist[src] = 1;
    amt[src] = 1;
    if(forw[src][m - 1] > 0)
    {
        if(!vist[forw[src][m - 1]])
            dfs(forw[src][m - 1]);
        amt[src] += amt[forw[src][m - 1]];
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    auto t = clock();
    cin >> n >> m;
    int pre;
    cin >> pre;
    for(int j = 1; j < n; j++)
    {
        cin >> forw[pre][0];
        pre = forw[pre][0];
    }
    for(int i = 1; i < m; i++)
    {
        int nxt;
        cin >> pre;
        for(int j = 1; j < n; j++)
        {
            cin >> nxt;
            if(forw[pre][i - 1] == nxt)
            {
                forw[pre][i] = nxt;
            }
            pre = nxt;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(!vist[i])
            dfs(i);
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++)
        ans += amt[i];
    cout << ans << endl;
}