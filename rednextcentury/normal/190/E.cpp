
#include <bits/stdc++.h>
using namespace std;
vector<int> adj;
map<int,int> is[1000000];
bool vis[1000000];
vector<int> ad[1000000];
int num=0;
int comp[1000000];
int sz;;
vector<int> ans[1000000];
void bfs(int v)
{
    sz=0;
    vis[v]=1;
    queue<int> q;
    q.push(v);
    while(!q.empty())
    {
        v=q.front();
        comp[sz++]=v;
        q.pop();
        vector<int> cur;
        num=0;
        for (int i=0;i<adj.size();i++)
        {
            int u=adj[i];
            while(num<ad[v].size() && ad[v][num]<u)
                num++;
            if (num<ad[v].size() && ad[v][num]==u)
            {
                cur.push_back(u);
                continue;
            }
            if (vis[u])continue;
            vis[u]=1;
            q.push(u);
        }
        adj=cur;
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)adj.push_back(i);
    for (int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        ad[x].push_back(y);
        ad[y].push_back(x);
    }
    for (int i=1;i<=n;i++)
        sort(ad[i].begin(),ad[i].end());
    int ret=0;
    for (int i=1;i<=n;i++)
    {
        if (!vis[i])
        {
            bfs(i);
            ans[ret].push_back(sz);
            for (int j=0;j<sz;j++)
                ans[ret].push_back(comp[j]);
            ret++;
        }
    }
    printf("%d\n",ret);
    for (int i=0;i<ret;i++)
    {
        for (int j=0;j<ans[i].size();j++)
            printf("%d ",ans[i][j]);
        printf("\n");
    }

}