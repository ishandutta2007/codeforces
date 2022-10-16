
# include <bits/stdc++.h>
using namespace std;
char s[53][53];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int vis[53][53], n, m, flag=0;
void dfs(int x, int y, int pre)
{
    if(flag) return;
    vis[x][y] = 1;
    for(int i=0; i<4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m || (s[nx][ny] != s[x][y]) || (i+2)%4==pre) continue;
        if(vis[nx][ny])
        {
            flag = 1;
            return;
        }
        dfs(nx, ny, i);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; ++i)
    {
        scanf("%s",s[i]);
    }
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            if(!vis[i][j])
            {
                dfs(i, j, -1);
                if(flag) 
				{
					cout<<"Yes"<<endl;return 0;
				}
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}