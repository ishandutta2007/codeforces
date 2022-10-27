#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
typedef long long LL;
const int NICO = 100000 + 10;
int n, a[NICO];
vector<int> vec[NICO];
int dp[NICO][31][2];LL res;
void dfs(int x, int par)
{
    for(int i=0;i<30;i++)
    {
        if((1<<i)&a[x]) dp[x][i][1] = 1;
        else dp[x][i][0] = 1;
    }
    for(int i=0;i<vec[x].size();i++)
    {
        int cur = vec[x][i];
        if(cur == par) continue;
        dfs(cur, x);
        for(int j=0;j<30;j++)
        {
            res += ((LL)dp[cur][j][0]*dp[x][j][1] + (LL)dp[cur][j][1]*dp[x][j][0]) << j;//
            int t = (a[x]>>j)&1;
            dp[x][j][0^t] += dp[cur][j][0];
            dp[x][j][1^t] += dp[cur][j][1];
        }
    }
}
int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
        res += a[i]; //0
    }
    for(int i=1;i<n;i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs(1, 0);
    cout << res << endl;
}