#include<bits/stdc++.h>
using namespace std;
char a[2009][2009];
int I,J;
int d[2009][2009];
int F[2009][2009];
int n,m,k;
int dx[4]={1,0,0,-1};
int dy[4]={0,-1,1,0};
string ans="";
char dc[4]={'D','L','R','U'};
bool c(int x, int y)
{
    if(x < n &&  x >=0 && y <m && y >=0 && a[x][y]!='*') return true;
    return false;
}
void dfs(int x, int y, int K)
{
    for (int i=0; i<4; i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(!c(nx,ny)) continue;
        if(d[nx][ny] <= K-1)
        {
            ans+=dc[i];
            dfs(nx,ny,K-1);
            return;
        }
    }
}
main()
{
    cin >> n >> m >> k;
    for (int i =0; i < n; i++)
    {
        cin >> a[i];
         for (int j =0; j < m; j++)
        if(a[i][j]=='X') I = i, J =j;
    }
    int fl=0;
    for (int i=0; i<4; i++)
        if(c(I+dx[i],J+dy[i])) fl=1;
    if(k%2 || fl==0) {cout<<"IMPOSSIBLE"<<endl; return 0;}
    queue<pair<int,int> > q;
    q.push({I,J});
    d[I][J]=0;
    F[I][J]=1;
    while(q.size())
    {
        pair<int,int> T=q.front(); q.pop();
        for (int i=0; i < 4; i++)
        {
            int nx=T.first+dx[i];
            int ny=T.second+dy[i];
            if(c(nx,ny) && F[nx][ny]==0 )
            {
                q.push({nx,ny});
                d[nx][ny]=d[T.first][T.second]+1;
                F[nx][ny]=1;
            }
        }
    }
    dfs(I,J,k);
    cout << ans <<endl;
}