#include<iostream>
# include <algorithm>
#include <vector>
#include<ios>
using namespace std;
vector<int> adj[1000000];
vector<int> type[1000000];
bool vis[1000000];
vector<int> ans;
int dp[1000000];
void dfs(int v)
{
    vis[v]=1;
    int n=adj[v].size();
    for (int i=0;i<n;i++)
    {
        int u=adj[v][i];
        if (vis[u])
            continue;
        dfs(u);
        if (type[v][i]==2)
        {
            if (dp[u]>0)
                dp[v]+=dp[u];
            else
            {
                dp[v]=1;
                ans.push_back(u);
            }
        }
        else
            dp[v]+=dp[u];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
        type[a-1].push_back(c);
        type[b-1].push_back(c);
    }
    dfs(0);
    cout<<ans.size()<<endl;
    int k=ans.size();
    for (int i=0;i<k;i++)
        cout<<" "<<ans[i]+1;
    cout<<endl;
}