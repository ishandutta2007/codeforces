#include <bits/stdc++.h>

using namespace std;
int vis[100005];
long long a[100005];
vector<vector<int> >adj1,adj2;
long long cost=10000000000000;
long long  w=1;
int n;
stack <int>s;
vector<vector<int> >nodes;
    vector<int>v;


void dfs_build(int node)
{
    vis[node]=1;
    for(int i=0; i<adj1[node].size(); i++)
    {
        if(!vis[adj1[node][i]])
        {
            dfs_build(adj1[node][i]);
        }
    }
    s.push(node);

}

void dfs_count_Cycle (int node)
{
    vis[node]=1;
    v.push_back(node);
    for(int i=0; i<adj2[node].size(); i++)
    {
        if(!vis[adj2[node][i]])
        {
            dfs_count_Cycle(adj2[node][i]);
        }
    }

}
vector<vector<int> > Scc()
{
    vector<vector<int> > arry_Scc(n+1);
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            dfs_build(i);
        }
    }
    memset(vis,0,sizeof vis);
    while(!s.empty())
    {
        int node=s.top();
        s.pop();
        if(!vis[node])
        {
            v.clear();
            dfs_count_Cycle(node);
            arry_Scc[node]=v;

        }
    }
    return arry_Scc;

}
void dfs(int node)
{
    vis[node]=1;
    for(int i=0; i<nodes[node].size(); i++)
    {
        if(!vis[nodes[node][i]])
        {
            if(cost>a[nodes[node][i]-1])
            {
                cost=a[nodes[node][i]-1];
                w=1;
            }
            else if(cost==a[nodes[node][i]-1])
            {
                w++;
            }
            dfs(nodes[node][i]);
        }
    }
}



int main()
{

    cin>>n;
    adj1.resize(n+3);
    adj2.resize(n+3);
    for(int i=0; i<n; i++)
        cin>>a[i];
    int m;
    cin>>m;
    for(int i=0; i<m; i++)
    {
        long long x,y;
        cin>>x>>y;
        adj1[x].push_back(y);
        adj2[y].push_back(x);

    }

    nodes=Scc();
    
    
    memset(vis,0,sizeof vis);
    long long sum=0,z=1;
    for(int i=1; i<=n; i++)
    {
            if(!vis[i] && nodes[i].size())
            {
                cost=a[i-1];
                w=1;
                dfs(i);
                z=(z%1000000007*w%1000000007)%1000000007;
                sum+=cost;
            }
    }
    cout<<sum<<" "<<z<<endl;




    return 0;
}