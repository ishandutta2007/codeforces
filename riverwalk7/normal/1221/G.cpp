#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
typedef long long ll;
const ll N = 40;
const ll C = 1<<(N/2);
ll n, m;
int u, v;
int x[N], y[N/2];
ll DP[C];
bool flag;
int cur; ll tot;
ll s, t;
int color[N];
bool isBipartite; ll totcomp, single;
vector<int> conn[N];
ll ans;
void dfs(int node)
{
    for(int i=0; i<conn[node].size(); i++)
    {
        if(!color[conn[node][i]])
        {
            flag = true;
            color[conn[node][i]] = 3-color[node];
            dfs(conn[node][i]);
        }
        else if(color[conn[node][i]] == color[node])
        {
            isBipartite = false;
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>u>>v;
        --u; --v;
        conn[u].push_back(v); conn[v].push_back(u);
        if(u < N/2 && v < N/2)
        {
            x[u] ^= (1<<v);
            x[v] ^= (1<<u);
        }
        else if(u >= N/2 && v >= N/2)
        {
            x[u] ^= (1<<(v-N/2));
            x[v] ^= (1<<(u-N/2));
        }
        else
        {
            if(u > v) swap(u, v);
            y[u] ^= (1<<(v-N/2));
        }
    }
    isBipartite = true;
    for(int i=0; i<N; i++)
    {
        if(!color[i])
        {
            flag = false;
            color[i] = 1;
            dfs(i);
            if(!flag) ++single;
            ++totcomp;
        }
    }
    for(int i=0; i<C; i++)
    {
        flag = true;
        for(int j=N/2; j<N; j++)
        {
            if(i & x[j] && i & 1<<(j-N/2))
            {
                flag = false;
            }
        }
        if(flag)
        {
            DP[i] = 1;
        }
    }
    for(int i=0; i<N/2; i++)
    {
        for(int j=0; j<C; j++)
        {
            if(j & (1<<i))
            {
                DP[j] += DP[j^1<<i];
            }
        }
    }
    for(int i=0; i<C; i++)
    {
        flag = true;
        for(int j=0; j<N/2; j++)
        {
            if(i & x[j] && i & 1<<j)
            {
                flag = false;
            }
        }
        if(flag)
        {
            cur = 0;
            for(int j=0; j<N/2; j++)
            {
                if(i & (1<<j)) cur |= y[j];
            }
            tot += DP[C-1-cur];
        }
    }
    ans = C*C-2*tot-(1LL<<totcomp)+2*(1LL<<single);
    if(isBipartite) ans += (1LL<<totcomp);
    if(totcomp == N) ans -= C*C;
    ans = ans >> (N-n);
    cout<<ans<<endl;
}