#include<stdio.h>
#include<cstring>
using namespace std;
char ans[15][15];
char t[15][15];int res;
int Max[15];
char shape[5][5][5];
int n,m;
bool check(int x,int y,int type)
{
     for(int i=0;i<3;i++)
     for(int j=0;j<3;j++)
     if(shape[type][i][j]=='j')
     if(t[x+i][y+j]!='.')return 0;
     return 1;
}
void putshape(int x,int y,int type,int u)
{
     for(int i=0;i<3;i++)
     for(int j=0;j<3;j++)
     if(shape[type][i][j]=='j')
     t[x+i][y+j]=u;
}
void dfs(int x,int y,int now)
{
     if(x>n)
     {
            if(now-'A'>=res)
            {
                        for(int i=1;i<=n;i++)
                        for(int j=1;j<=m;j++)
                        ans[i][j]=t[i][j];
                        res=now-'A';
            }
            return;
            }
     int dx=x;int dy=y;dy++;
     if(dy>m)dy=1,dx++;
     if(now-'A'>Max[x]){Max[x]=now-'A';}
     if(now-'A'<Max[x]-3)return;
     for(int i=0;i<4;i++)
     if(check(x,y,i))
     {
                     putshape(x,y,i,now);
                     dfs(dx,dy,now+1);
                     putshape(x,y,i,'.');
                     }
     dfs(dx,dy,now);
}
void init()
{
     for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
     t[i][j]='.';
     shape[0][0][0]=shape[0][0][1]=shape[0][0][2]=shape[0][1][1]=shape[0][2][1]='j';
     
     shape[1][2][0]=shape[1][2][1]=shape[1][2][2]=shape[1][0][1]=shape[1][1][1]='j';
     
     shape[2][0][2]=shape[2][1][2]=shape[2][2][2]=shape[2][1][0]=shape[2][1][1]='j';
     
     shape[3][0][0]=shape[3][1][0]=shape[3][2][0]=shape[3][1][1]=shape[3][1][2]='j';
}
int main()
{
    scanf("%d%d",&n,&m);
    init();
    dfs(1,1,'A');
    printf("%d\n",res);
    for(int i=1;i<=n;i++)
    {
            for(int j=1;j<=m;j++)putchar(ans[i][j]);
            putchar('\n');
            }
    return 0;
}