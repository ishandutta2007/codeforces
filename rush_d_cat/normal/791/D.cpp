#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
typedef long long LL;
const int NICO = 200000 + 10;

vector<int> G[NICO];
LL n, k, u, v;
LL dp[NICO][6];
LL cnt[NICO], sum[NICO], add[6];
LL ans, s1, s2;
void dfs1(LL cur, LL par, LL rk)
{
    cnt[cur] = 1;
    dp[cur][k] = 1;
    sum[1] += rk;
    for(int i=0;i<G[cur].size();i++)
    {
        int x = G[cur][i];
        if(x == par) continue;
        dfs1(x, cur, rk+1); 
        cnt[cur] += cnt[x];
        for(int j=2;j<=k;j++)
        {
            dp[cur][j] += dp[x][j-1];
        }
        dp[cur][1] += dp[x][k];
    }
}

void dfs2(LL cur, LL par)
{
    for(int i=0;i<G[cur].size();i++)
    {
        int x = G[cur][i];
        if(x == par) continue;
        sum[x] = sum[cur] + n - cnt[x] - cnt[x];
        dp[x][0] = dp[x][k];
        for(int j=1;j<=k;j++)
        {
            add[j+1] = dp[cur][j] - dp[x][j-1];
        }
        add[1] = add[k+1];
        for(int j=1;j<=k;j++)
        {
            dp[x][j] += add[j];
        }
        dfs2(x, cur);
    }
}

int main()
{
    scanf("%d %d", &n, &k);
    for(int i=1;i<n;i++)
    {
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1, 0, 0);
    dfs2(1, 0);
    for(int i=1;i<=n;i++)
    {
        s1 += sum[i];
        for(int j=1;j<=k;j++)
        {
            if(j==k) dp[i][j] --;
            s2 += j * dp[i][j];
        }
    }
    ans = (s1 - s2) / 2 / k;
    ans += (LL)n*(n-1)/2;
    cout << (ans) << endl;
}