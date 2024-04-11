#include<iostream>
# include <cstring>
#include <vector>
#include<ios>
using namespace std;
vector<int> adj[1000000];
bool vis[1000000];
int s[1000];
int e[1000];
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
    }
}
int main()
{
    int tot=0;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if (x==1)
        {
            cin>>s[tot]>>e[tot];
            tot++;
            for (int j=0;j<tot;j++)
            {
                if ((s[tot-1]>s[j] && s[tot-1]<e[j]) || (e[tot-1]>s[j] && e[tot-1]<e[j]))
                {
                    adj[tot-1].push_back(j);
                }
                if ((e[j]>s[tot-1] && e[j]<e[tot-1])|| (s[j]>s[tot-1] && s[j]<e[tot-1])  )
                    adj[j].push_back(tot-1);
            }
        }
        else
        {
            int si,ei;
            cin>>si>>ei;
            si--;
            ei--;
            memset(vis,0,sizeof(vis));
            dfs(si);
            if (vis[ei])
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
}