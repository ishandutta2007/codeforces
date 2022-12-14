#include<bits/stdc++.h>
using namespace std;
int dist[3001][3001];
bool vis[3001][3001];
vector<int> adj[1000000];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    dist[s][s]=0;
    vis[s][s]=1;
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        for (int i=0;i<adj[v].size();i++)
        {
            if (vis[s][adj[v][i]])continue;
            dist[s][adj[v][i]]=dist[s][v]+1;
            vis[s][adj[v][i]]=1;
            q.push(adj[v][i]);
        }
    }
}
int f1[4000][3];
int f2[4000][3];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int s,e;
        cin>>s>>e;
        adj[s].push_back(e);
    }
    memset(dist,-1,sizeof dist);
    for (int i=1;i<=n;i++)
        bfs(i);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (i==j)
                continue;
            if (dist[i][j]>dist[i][f1[i][0]])
            {
                f1[i][2]=f1[i][1];
                f1[i][1]=f1[i][0];
                f1[i][0]=j;
            }
            else if (dist[i][j]>dist[i][f1[i][1]])
            {
                f1[i][2]=f1[i][1];
                f1[i][1]=j;
            }
            else if (dist[i][j]>dist[i][f1[i][2]])
                f1[i][2]=j;
            if (dist[i][j]>dist[f2[j][0]][j])
            {
                f2[j][2]=f2[j][1];
                f2[j][1]=f2[j][0];
                f2[j][0]=i;
            }
            else if (dist[i][j]>dist[f2[j][1]][j])
            {
                f2[j][2]=f2[j][1];
                f2[j][1]=i;
            }
            else if (dist[i][j]>dist[f2[j][2]][j])
                f2[j][2]=i;
        }
    }
    int A,B,C,D;
    int ans=-1;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (i==j)continue;
            int b=i,c=j;
            if (dist[b][c]==-1)
                continue;
            for (int x=0;x<3;x++)
            {
                for (int k=0;k<3;k++)
                {
                    int a=f2[b][x];
                    int d=f1[c][k];
                    if (a==d || a==b || a==c || d==b || d==c)
                        continue;
                    if (dist[a][b]==-1 || dist[c][d]==-1)
                        continue;
                    if (dist[a][b]+dist[b][c]+dist[c][d]>ans)
                        ans=dist[a][b]+dist[b][c]+dist[c][d],A=a,B=b,C=c,D=d;
                }
            }
        }
    }
    cout<<A<<" "<<B<<" "<<C<<" "<<D<<endl;
}