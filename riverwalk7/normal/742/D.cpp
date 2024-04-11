#include <iostream>
#include <fstream>
#include <vector>
#define MAXN 1010
using namespace std;
int N, M, W;
int w[MAXN];
int b[MAXN];
int DP[MAXN][MAXN];
bool vis[MAXN];
int x, y, counter;
int sum, sum1;
vector<int> conn[MAXN];
vector<int> groups[MAXN];
int ans;
void dfs(int node)
{
    if(vis[node])
    {
        return;
    }
    else
    {
        vis[node] = true;
        groups[counter].push_back(node);
        for(int j=0; j<conn[node].size(); j++)
        {
            dfs(conn[node][j]);
        }
    }
}
int main()
{
    cin>>N>>M>>W;
    for(int i=1; i<=N; i++)
    {
        cin>>w[i];
    }
    for(int i=1; i<=N; i++)
    {
        cin>>b[i];
    }
    for(int i=0; i<M; i++)
    {
        cin>>x>>y;
        conn[x].push_back(y);
        conn[y].push_back(x);
    }
    for(int i=1; i<=N; i++)
    {
        if(!vis[i])
        {
            ++counter;
            dfs(i);
        }
    }
    for(int i=1; i<=counter; i++)
    {
        sum = 0; sum1 = 0;
        for(int k=0; k<=W; k++)
        {
            DP[i][k] = DP[i-1][k];
        }
        for(int j=0; j<groups[i].size(); j++)
        {
            for(int k=w[groups[i][j]]; k<=W; k++)
            {
                DP[i][k] = max(DP[i][k], DP[i-1][k-w[groups[i][j]]] + b[groups[i][j]]);
            }
            sum += w[groups[i][j]];
            sum1 += b[groups[i][j]];
        }
        for(int k=sum; k<=W; k++)
        {
            DP[i][k] = max(DP[i-1][k-sum] + sum1, DP[i][k]);
        }
    }
    cout<<DP[counter][W]<<endl;
}