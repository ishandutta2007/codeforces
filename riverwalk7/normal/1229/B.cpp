#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define MAXN 100100
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int parent[17][MAXN];
ll f[17][MAXN]; //f of the node until the 2^jth ancestor
int N;
ll x[MAXN];
int level[MAXN];
int u, v;
ll cur; int cur2; ll cur3, ans;
vector<int> conn[MAXN];
void dfs(int node)
{
    for(int i=0; i<conn[node].size(); i++)
    {
        if(conn[node][i]!=parent[0][node])
        {
            parent[0][conn[node][i]] = node;
            level[conn[node][i]] = level[node]+1;
            dfs(conn[node][i]);
        }
    }
}
int main()
{
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        cin>>x[i];
    }
    for(int i=0; i<N-1; i++)
    {
        cin>>u>>v;
        conn[u].push_back(v);
        conn[v].push_back(u);
    }
    level[1] = 1;
    dfs(1);
    for(int i=1; i<=N; i++)
    {
        f[0][i] = x[i];
    }
    for(int i=1; i<17; i++)
    {
        for(int j=1; j<=N; j++)
        {
            f[i][j] = __gcd(f[i-1][j], f[i-1][parent[i-1][j]]);
            parent[i][j] = parent[i-1][parent[i-1][j]];
        }
    }
    for(int i=1; i<=N; i++)
    {
        cur = x[i];
        cur2 = i;
        while(cur2)
        {
            cur3 = 0;
            for(int j=16; j>=0; j--)
            {
                if(cur && f[j][cur2] % cur == 0 && level[cur2] >= (1<<j))
                {
                    cur3 += (1<<j);
                    cur2 = parent[j][cur2];
                }
                else if(f[j][cur2] == 0 && cur == 0 && level[cur2] >= (1<<j))
                {
                    cur3 += (1<<j);
                    cur2 = parent[j][cur2];
                }
            }
            ans += cur3 * cur;
            ans %= MOD;
            cur = __gcd(x[cur2], cur);
        }
    }
    cout<<ans<<endl;
}