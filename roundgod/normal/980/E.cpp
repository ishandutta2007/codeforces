#include<bits/stdc++.h>
#define MAXV 1000005
#define MAXLOGV 22
using namespace std;
vector<int> G[MAXV];
int root;
int parent[MAXLOGV][MAXV];
int n,k;
bool used[MAXV];
vector<int> ans;
void dfs(int v,int p)
{
    parent[0][v]=p;
    for(int i=0;i<G[v].size();i++)
        if(G[v][i]!=p) dfs(G[v][i],v);
}
void init(int V)
{
    dfs(root,-1);
    for(int k=0;k+1<MAXLOGV;k++)
    {
        for(int v=1;v<=V;v++)
        {
            if(parent[k][v]<0) parent[k+1][v]=-1;
            else parent[k+1][v]=parent[k][parent[k][v]];
        }
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    root=n;
    init(n);
    memset(used,false,sizeof(used));
    k=n-k;
    k--;used[n]=true;ans.push_back(n);
    for(int i=n-1;i>=1;i--)
    {
        if(k==0) break;
        if(used[i]) continue;
        int d=1,v=i;
        for(int j=MAXLOGV-1;j>=0;j--)
        {
            if(parent[j][v]!=-1&&!used[parent[j][v]]) 
            {
                d+=1<<j;
                v=parent[j][v];
            }
        }
        if(d>k) continue;
        else
        {
            k-=d;v=i;
            while(!used[v])
            {
                used[v]=true;
                ans.push_back(v);
                v=parent[0][v];
            }
        }
    }
    set<int> s(ans.begin(),ans.end());
    for(int i=1;i<=n;i++)
        if(!s.count(i)) printf("%d ",i);
    return 0;
}