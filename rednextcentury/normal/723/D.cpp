#include<bits/stdc++.h>
using namespace std;
pair<int,pair<int,int> > lakes[1000000];
int tot=0;
bool is=1;
int sz;
int n,m;
char a[100][100];
bool vis[100][100];
int mv[][2]={{0,1},{1,0},{0,-1},{-1,0}};
void dfs(int x,int y)
{
    vis[x][y]=1;
    sz++;
    if (x==0 || x==n-1 || y==0 || y==m-1)
        is=0;
    for (int i=0;i<4;i++)
    {
        int X=x+mv[i][0];
        int Y=y+mv[i][1];
        if (X<0 || X>=n || Y<0 || Y>=m)
            continue;
        if (a[X][Y]=='.' && !vis[X][Y])
            dfs(X,Y);
    }
}
int ret=0;
void change(int x,int y)
{
    vis[x][y]=1;
    a[x][y]='*';
    ret++;
    for (int i=0;i<4;i++)
    {
        int X=x+mv[i][0];
        int Y=y+mv[i][1];
        if (X<0 || X>=n || Y<0 || Y>=m)
            continue;
        if (a[X][Y]=='.' && !vis[X][Y])
            change(X,Y);
    }
}
int main()
{
    int k;
    cin>>n>>m>>k;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin>>a[i][j];
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (a[i][j]=='.' && !vis[i][j])
            {
                is=1;
                sz=0;
                dfs(i,j);
                if (is)
                    lakes[tot++]=make_pair(sz,make_pair(i,j));
            }
        }
    }
    sort(lakes,lakes+tot);
    int num=tot-k;
    memset(vis,0,sizeof(vis));
    for (int i=0;i<num;i++)
        change(lakes[i].second.first,lakes[i].second.second);
    cout<<ret<<endl;
    for (int i=0;i<n;i++)
        cout<<a[i]<<endl;
}