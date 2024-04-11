#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long LL;
const LL MOD = 1000000000 + 7;
LL p, k, ans = 1;
int vis[1000002];
void dfs(int x, LL t)
{
    if(vis[x])
    {
        return;
    }
    ans = ans * t % MOD;
    vis[x] = 1;
    dfs(k*x%p, 1);
}
int main()
{
    cin >> p >> k;
    vis[0] = 1;
    ans = k==1?p:1;
    for(int i=1;i<p;i++)
    {
        dfs(i, p);
    }
    cout << ans << endl;
}