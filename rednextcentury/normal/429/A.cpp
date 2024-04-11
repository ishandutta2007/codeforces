#include <iostream>
#include <map>
#include <string>
# include <stdio.h>
# include <map>
# include <queue>
# include <ios>
# include <vector>
# include <algorithm>
using namespace std;
vector<int> a[100000];
bool visited[100000];
bool need[100000];
queue<int> ans;
void dfs(int v,bool flip,bool forflip)
{
    visited[v]=1;
    bool p=1;
    for (int i=0;i<a[v].size();i++)
    {
        if (!visited[a[v][i]])
        {
        if (flip)
        {
            if (!need[v])
            {
                if (p==1)
                ans.push(v);
                dfs(a[v][i],forflip,1-flip);
                
            p=0;
            }
            else
            {
                dfs(a[v][i],forflip,flip);
                
            p=0;
            }
        }
        else
        {
            if (need[v])
            {
                if (p==1)
                ans.push(v);
                dfs(a[v][i],forflip,1-flip);
                
            p=0;
            }
            else
            {
                dfs(a[v][i],forflip,flip);
                
            p=0;
            }
        }
        }
    }
    if (p==1 && ((need[v] && !flip )|| (flip && !need[v])))
        ans.push(v);

}
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for (int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u-1].push_back(v-1);
        a[v-1].push_back(u-1);
    }
    for (int i=0;i<n;i++)
    {
        cin>>need[i];
    }
    for (int i=0;i<n;i++)
    {
        bool k;
        cin>>k;
        if (k==need[i])
            need[i]=0;
        else
            need[i]=1;
    }
    dfs(0,0,0);
    cout<<ans.size()<<"\n";
    while(!ans.empty())
    {
        cout<<ans.front()+1<<"\n";
        ans.pop();
    }
}