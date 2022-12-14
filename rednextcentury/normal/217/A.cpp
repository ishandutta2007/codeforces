#include<iostream>
# include <queue>
#include <vector>
using namespace std;
vector<int> adj[100000];
int x[1000];
bool vi[1000];
int y[1000];
void dfs(int v)
{
    vi[v]=1;
    int n=adj[v].size();
    for (int i=0;i<n;i++)
    {
        int u=adj[v][i];
        if (vi[u])
            continue;
        dfs(u);
    }
}
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>x[i]>>y[i];
    for (int i=0;i<n;i++)
    {
        for (int j=i-1;j>=0;j--)
        {
            if (x[j]==x[i] || y[j]==y[i])
                adj[j].push_back(i),adj[i].push_back(j);
        }
    }
    int ans=-1;
    for (int i=0;i<n;i++)
    {
        if (!vi[i])
            dfs(i),ans++;
    }
    cout<<ans<<endl;
}