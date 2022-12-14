#include <bits/stdc++.h>

using namespace std;
bool visited[110],Deleted[110];
int a,b,n,m,ans,flag;
vector<int> G[110];
vector<int>::iterator it;
void dfs(int x)
{
    if(visited[x])
        return;
    visited[x]=1;
    if(G[x].size()==1)
    {
        Deleted[x]=1;//mark x as having one child only
    }
    for(auto j:G[x])
        dfs(j);

}


int main()
{
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=1; i<=n; i++)
    {
        flag=0;
        for (int j=1;j<=n;j++)
        {
            if (!visited[j])
                dfs(j);
        }
        memset(visited,0,sizeof(visited));
        for(int j=1; j<=n; j++)
        {
            if(Deleted[j])  // element j got size 1
            {
                flag=1;
                if(G[j].size() >0)
                {
                    int z=G[j][0];
                    G[j].erase(G[j].begin()+0);//erase j's only child

                    if(G[z].size() >0)
                    {
                        it=std::find(G[z].begin(),G[z].end(),j);
                        if(it!=G[z].end())
                            G[z].erase(it);//erase j from its child
                    }
                }


            }
        }
        memset(Deleted,0,sizeof(Deleted));
        ans+=(flag);

    }
    cout<<ans;
    return 0;
}