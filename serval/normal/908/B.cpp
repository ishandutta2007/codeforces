#include <cstdio>
using namespace std;
int n,m,i,j;
int sx,sy,ex,ey;
int map[100][100];
char ctr[200];
char c;
const int dc[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int choice[10];
bool chosen[10];
int ans;
bool check()
{
    int x=sx,y=sy;
    for (int i=0;ctr[i];i++)
    {
        x+=dc[choice[ctr[i]-'0']][0];
        y+=dc[choice[ctr[i]-'0']][1];
        if (x==ex&&y==ey)
            return 1;
        if (map[x][y]==0)
            return 0;
    }
    return 0;
}
void dfs(int dep)
{
    if (dep==4)
    {
        if (check())
            ans++;
        return;
    }
    int i;
    for (i=0;i<4;i++)
        if (!chosen[i])
        {
            choice[dep]=i;
            chosen[i]=1;
            dfs(dep+1);
            chosen[i]=0;
        }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
        {
            scanf("%c",&c);
            while (c!='.'&&c!='S'&&c!='E'&&c!='#')
                scanf("%c",&c);
            if (c=='S')
            {
                sx=i;
                sy=j;
            }
            if (c=='E')
            {
                ex=i;
                ey=j;
            }
            if (c=='.'||c=='S'||c=='E')
                map[i][j]=1;
        }
    scanf("%s",ctr);
    dfs(0);
    printf("%d\n",ans);
    return 0;
}