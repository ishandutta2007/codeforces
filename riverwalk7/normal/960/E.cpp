#include <iostream>
#include <fstream>
#include <vector>
#define MAXN 200100
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
ll N;
ll v[MAXN], b[MAXN], w[MAXN], x[MAXN];
int parent[MAXN];
int xx, y;
ll tb, tw, ans;
ll s[MAXN];
ll cur;
vector<int> conn[MAXN];
void dfs(int node, int par, bool level)
{
    parent[node] = par;
    if(!level)
    {
        b[node] = 1;
        tb++;
    }
    else
    {
        w[node] = 1;
        s[node] = 1;
        tw++;
    }
    for(int i=0; i<conn[node].size(); i++)
    {
        if(conn[node][i]!=par)
        {
            dfs(conn[node][i], node, !level);
            b[node] += b[conn[node][i]];
            w[node] += w[conn[node][i]];
        }
    }
    x[node] = b[node] + w[node];
}
int main()
{
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        cin>>v[i];
    }
    for(int i=0; i<N-1; i++)
    {
        cin>>xx>>y;
        conn[xx].push_back(y);
        conn[y].push_back(xx);
    }
    dfs(1, 0, 0);
    for(int i=1; i<=N; i++)
    {
        cur = 0;
        for(int j=0; j<conn[i].size(); j++)
        {
            if(conn[i][j]!=parent[i]){
            cur += b[conn[i][j]]*(N-x[conn[i][j]]);
            cur -= w[conn[i][j]]*(N-x[conn[i][j]]);
            }
        }
        cur += (tb-b[i])*(x[i]);
        cur -= (tw-w[i])*(x[i]);
        if(s[i]==1)
        {
            cur = -cur;
        }
        cur += (N);
        cur = ((cur%MOD)+MOD)%MOD;
        cur *= v[i];
        cur = ((cur%MOD)+MOD)%MOD;
        ans += cur;
        ans %= MOD;
    }
    ans %= MOD;
    cout<<ans<<endl;
}