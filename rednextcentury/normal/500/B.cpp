#include<iostream>
# include <cstring>
#include <algorithm>
#include <stdio.h>
#include<vector>
using namespace std;
vector<int> adj[100000];
vector<int> idx[100000];
vector<int> nums[100000];
int val[1000000];
bool vis[100000];
int tot;
void dfs(int v)
{
    vis[v]=1;
    nums[tot].push_back(val[v]);
    idx[tot].push_back(v);
    int n=adj[v].size();
    for (int i=0;i<n;i++)
    {
        int u=adj[v][i];
        if (vis[u])
            continue;
        dfs(u);
    }
}
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>val[i];
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            char x;
            cin>>x;
            if (x=='1')
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    tot=0;
    for (int i=0;i<n;i++)
    {
        if (!vis[i])
            dfs(i),tot++;
    }
    for (int i=0;i<tot;i++)
    {
        int l=idx[i].size();
        sort(idx[i].begin(),idx[i].end());
        sort(nums[i].begin(),nums[i].end());
        for (int j=0;j<l;j++)
            val[idx[i][j]]=nums[i][j];
    }
    for (int i=0;i<n;i++)
        cout<<val[i]<<" ";
    cout<<endl;
}