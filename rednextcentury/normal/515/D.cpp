#include <bits/stdc++.h>
using namespace std;
char a[2005][2005];
int mv[][2]={{0,1},{1,0},{0,-1},{-1,0}};
vector<pair<int,int> > adj[2005][2005];
int deg[2005][2005];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",&a[i]);
        for (int j=m;j>=1;j--)
            a[i][j]=a[i][j-1];
    }
    for (int i=0;i<=n;i++)
        a[i][0]=a[i][m+1]='*';
    for (int i=0;i<=m;i++)
        a[0][i]=a[n+1][i]='*';
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            for (int k=0;k<4;k++)
            {
                int I=i+mv[k][0];
                int J=j+mv[k][1];
                if (a[I][J]=='.')
                {
                    adj[i][j].push_back(make_pair(I,J));
                    deg[i][j]++;
                }
            }
        }
    }
    queue<pair<int,int> > q;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (deg[i][j]==1)
                q.push(make_pair(i,j));
        }
    }
    while(!q.empty())
    {
        pair<int,int> v=q.front();
        q.pop();
        if (a[v.first][v.second]!='.')continue;
        if (deg[v.first][v.second]!=1)continue;
        int op=0;
        pair<int,int> u;
        while(1)
        {
            u = adj[v.first][v.second][op];
            if (a[u.first][u.second]=='.')
                break;
            op++;
        }
        if(--deg[u.first][u.second]==1)
            q.push(u);
        if (u.first==v.first)
        {
            a[u.first][max(u.second,v.second)]='>';
            a[u.first][min(u.second,v.second)]='<';
        }
        else
        {
            a[max(v.first,u.first)][u.second]='v';
            a[min(v.first,u.first)][u.second]='^';
        }
        for (int i=0;i<adj[u.first][u.second].size();i++)
        {
            if (--deg[adj[u.first][u.second][i].first][adj[u.first][u.second][i].second]==1)
                q.push(make_pair(adj[u.first][u.second][i].first,adj[u.first][u.second][i].second));
        }
    }
    int no=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if(a[i][j]=='.')
                no=1;
    if(no)printf("Not unique\n");
    else
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
                printf("%c",a[i][j]);
            printf("\n");
        }
    }
}