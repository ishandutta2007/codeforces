#include <iostream>
#include <fstream>
#define MAXN 1010
#define MOD 1000000007
using namespace std;
typedef long long ll;
bool adj[MAXN][MAXN];
ll choose[MAXN][MAXN];
bool vis[MAXN];
ll b[MAXN];
ll ans;
int M, N;
int c;
char s[MAXN];
void dfs(int n)
{
    if(vis[n])
    {
        return;
    }
    vis[n] = true; ++c;
    for(int i=0; i<M; i++)
    {
        if(adj[n][i])
        {
            dfs(i);
        }
    }
    return;
}
int main()
{
    cin>>M>>N;
    ans = 1;
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<M; j++)
        {
            adj[i][j] = true;
        }
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin>>s[j];
        }
        for(int j=0; j<M; j++)
        {
            for(int k=j+1; k<M; k++)
            {
                if(s[j]!=s[k])
                {
                    adj[k][j] = adj[j][k] = false;
                }
            }
        }
    }
    for(int i=0; i<MAXN; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(j==0)
            {
                choose[i][j] = 1;
            }
            else
            {
                choose[i][j] = choose[i-1][j-1]+choose[i-1][j];
            }
            choose[i][j] %= MOD;
        }
    }
    for(int i=0; i<MAXN; i++)
    {
        if(i==0)
        {
            b[i] = 1;
        }
        else
        {
            for(int j=0; j<i; j++)
            {
                b[i] += (choose[i-1][j] * b[j]);
                b[i] %= MOD;
            }
        }
    }
    for(int i=0; i<M; i++)
    {
        if(!vis[i])
        {
            c = 0;
            dfs(i);
            ans *= b[c];
            ans %= MOD;
        }
    }
    cout<<ans<<endl;
}